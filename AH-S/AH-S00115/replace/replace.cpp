#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
} a[1005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;string s,t;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	if(m==1){
		cout<<0;
	}
	else{
		for(int i=1;i<=m;i++){
			cin>>s>>t;
			if((int)s.size()!=(int)t.size())
				cout<<0<<endl;
			else{
				int l,r,ans=0;string d="",e="";
				for(int j=0;j<(int)s.size();j++){
					if(s[j]!=t[j]){
						l=j;break;
					}
				}
				for(int j=(int)s.size()-1;j>=0;j--){
					if(s[j]!=t[j]){
						r=j;break;
					}
				}
				for(int j=l;j<=r;j++){
					d+=s[j],e+=t[j];
				}
				for(int j=1;j<=n;j++){
					int f1=0,f2=0,f3=0,f4=0;
					for(int o=0;o<(int)a[j].s1.size();o++){
						int f=1;
						for(int p=o;p<o+(int)d.size();p++){
							if(a[j].s1[p]!=d[p-o])
								f=0;
						}
						if(f==1){
							f1=1;break;
						}
					}
					for(int o=0;o<(int)a[j].s2.size();o++){
						int f=1;
						for(int p=o;p<o+(int)e.size();p++){
							if(a[j].s2[p]!=e[p-o])
								f=0;
						}
						if(f==1){
							f2=1;break;
						}
					}
					for(int o=0;o<(int)s.size();o++){
						int f=1;
						for(int p=o;p<o+(int)a[j].s1.size();p++){
							if(s[p]!=a[j].s1[p-o])
								f=0;
						}
						if(f==1){
							f3=1;break;
						}
					}
					for(int o=0;o<(int)t.size();o++){
						int f=1;
						for(int p=o;p<o+(int)a[j].s2.size();p++){
							if(t[p]!=a[j].s2[p-o])
								f=0;
						}
						if(f==1){
							f4=1;break;
						}
					}
					if(f1==1&&f2==1&&f3==1&&f4==1)
						ans++;
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
