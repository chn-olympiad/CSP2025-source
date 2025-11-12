#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,T;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(T--){
		int ans=0;
		string s1,s2,q1,q2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0"<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int flag=0,pd=0;
			int len=a[i].size(),l,r;
			for(int j=0;j+len<=s1.size();j++){
				q1=s1.substr(j,len);
				if(q1==a[i]){
					l=j;
					pd=1;
					break;
				}
			}
			if(pd==0)continue;
			q2=s2.substr(l,len);
			if(q2==b[i])flag=1;
			for(int i=0;i<s2.size();i++){
				if(i>=l&&i<=l+len-1)continue;
				if(s2[i]!=s1[i]){
					flag=0;
				}
			}
			if(flag==1)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}//Ren5Jie4Di4Ling5%
