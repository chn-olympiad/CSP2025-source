#include<bits/stdc++.h>
using namespace std;
int t,n,m[100005][4],a[1000005],b[1000005],c[1000005],s[1000005],x,y,z,ans,maxx;
int tmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,x=0,y=0,z=0;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>m[i][j];
			}
		}
		for(int i=0;i<n;i++){
			a[i]=m[i][0];
			b[i]=m[i][1];
			c[i]=m[i][2];
		}
		sort(a,a+n,tmp);
		sort(b,b+n,tmp);
		sort(c,c+n,tmp);
		for(int i=0;i<n/2;i++){
			s[i]=a[i];
		}
		for(int i=0;i<n/2;i++){
			s[n/2+i]=b[i];
		}
		for(int i=0;i<n/2;i++){
			s[2*(n/2)+i]=c[i];
		}
		x=3*(n/2);
		sort(s,s+x,tmp);
		for(int i=0;i<n;i++){
			ans+=s[i];
		}
		cout<<ans;
	}
	return 0;
} 
