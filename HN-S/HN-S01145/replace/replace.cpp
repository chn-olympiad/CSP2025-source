#include<bits/stdc++.h>
using namespace std;
struct str{string sa,sb;}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i].sa>>a[i].sb;
	for(int i=1;i<=q;i++){
		string s1,s2;cin>>s1>>s2;
		int l,r,ans=0;
		bool f=0,f1=0,f2=0;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				ans++;l=i;
				while(s1[i]!=s2[i]){i++;r=i;}
			}
		}
		if(ans>=2){cout<<0<<'\n';continue;}
		//cout<<l<<' '<<r-1;
		int len=r-l;ans=0;
		for(int i=1;i<=n;i++){
			int lena=a[i].sa.size(),lenb=a[i].sb.size(); 
			if(lena==lenb&&lena>=len){
				for(int j=0;j+lena-1<=s1.size();j++){
					//cout<<i<<endl;
					string x,y;
					x=s1.substr(0,j);y=s1.substr(j+lena-1,s1.size()-(j+lena-1));
					//cout<<x<<' '<<a[i].sb<<' '<<y<<' '<<a[i].sa<<endl;
					if(x+a[i].sb+y==s2)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
