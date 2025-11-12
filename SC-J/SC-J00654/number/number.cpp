#include<bits/stdc++.h>
using namespace std;
string s;
int num[10],cnt=0;
int main(){
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ls=s.size();
	for(int i=0;i<ls ;i++){
		if('0'<=s[i]&&s[i]<='9'){
			num[s[i]-'0']++;
			cnt++;
		}
	}
	int ps=9;
	while(cnt--){
		if(num[ps]>=1){
			cout<<ps;
			num[ps]--;
		}else{
			ps--;
			cnt++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}