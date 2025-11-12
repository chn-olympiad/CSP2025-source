#include<bits/stdc++.h>
using namespace std;
int a[4][1000]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n=0;
		int c=0;
		int ans=0;
		int d=0,e=0,f=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			int aa=0,ab=0,ac=0;
			cin>>aa>>ab>>ac;
			c=max(aa,ab);
			c=max(c,ac);
			if(c==aa){
				if(d<n/2){
					d+=1;
					ans+=c;
					a[1][j]=c;
					}else{
						c=max(ab,ac);
						}
				}
				if(c==ab){
					if(e<n/2){
						e+=1;
						ans+=c;
						a[2][j]=c;
						}else{
							c=ac;
							}
					}
					if(c==ac){
						if(f<n/2){
							f+=1;
							ans+=c;
							a[3][j]=c;
							}
						}
			}
		cout<<ans<<endl;
	}
	return 0;
	}
