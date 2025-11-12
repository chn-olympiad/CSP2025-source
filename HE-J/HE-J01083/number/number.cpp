#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,as[1000007];
int main(){
	//ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		/*if('0'<=s[i]&&s[i]<='9'){
			sm++;
			int j=0;
			while(as[i]>(s[i]-'0')){
				j++;
				
			}
			as.insert((s[i]-'0'),j);
		}*/
		if('0'<=s[i]&&s[i]<='9'){
			as[++cnt]=(s[i]-'0');			
		}
	}
	//cout<<cnt;
	sort(as+1,as+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<as[i];
	}

	return 0;
}
