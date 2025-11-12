#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out ","w",stdout);
	string s;
	long long b[10]={};
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++; 
			//cout<<s[i]-'0'<<" "<<b[i]<<"\n";
		}
	}
	for(int i=9;i>=0;i--){
		//cout<<b[i]<<" ";
		if(b[i]!=0){
			for(int j=1;j<=b[i];j++){
				cout<<i;	
			}
		}
	}
	return 0;
}