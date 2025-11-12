#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[1005][2]={};
string s1="",s2="";
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=0,t=0;
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(t--){
		s1="",s2="";
		cin>>s1>>s2;
		int sum=0;
		//[0,i-1],[i,j],[j+1,s1.size()-1]
		for(int i=0;i<s1.size();i++){
			for(int j=i;j<s1.size();j++){
				string _1=s1.substr(0,i);
				string wenhao=s1.substr(i,j-i+1);
				string _3=s1.substr(j+1,s1.size()-1-j);
				for(int i=1;i<=n;i++){
					if(s[i][0]==wenhao){
						string _4=_1+s[i][1]+_3;
						if(_4==s2) sum++;
					}
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
