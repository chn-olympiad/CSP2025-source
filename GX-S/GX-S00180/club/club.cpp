#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	int g[t];
	for(int i=0;i<t;i++){
		cin>>n;
		int a,b,c,ans=0,d=0,e=0,f=0;
		for(int j=0;j<n;j++){
			cin>>a>>b>>c;
			if(a>=b && a>=c && d<n/2){
					ans+=a;
					d++;
			}
			if(b>=a && b>=c && e<n/2){
					ans+=b;
					e++;
			}
			if(c>=b && c>=a && f<n/2){
					ans+=c;
					f++;
			}
		}
		g[i]=ans;
	}
	for(int i=0;i<t;i++){
		cout<<g[i]<<endl;
	}
	return 0;
}
	

