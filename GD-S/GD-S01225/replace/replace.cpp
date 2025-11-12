#include<bits/stdc++.h>
using namespace std;
long long n,q;
string str[100010][2];
map<string,long long>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>str[i][0]>>str[i][1];
		mp[str[i][0]+str[i][1]]++;
	}
	for(int i=1;i<=q;i++){
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size()){
			printf("0\n");
			continue;
		}
		long long l=-1,r=-1,ans=0;
		for(int j=0;j<s.size();j++){
			if(s[j]==t[j])continue;
			if(l==-1)l=j;
			r=j;
		}
		string str1="",str2="",str3="",str4="";
		for(int j=l;j<=r;j++)str1+=s[j],str3+=t[j];
		for(int j=l;j>=0;j--){
			str2=str1,str4=str3;
			for(int k=r;k<s.size();k++){
				ans+=mp[str2+str4];
				str2=str2+s[k+1],str4=str4+t[k+1];
			}
			str1=s[j-1]+str1,str3=t[j-1]+str3;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
