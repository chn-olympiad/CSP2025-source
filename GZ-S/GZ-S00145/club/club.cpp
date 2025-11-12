//GZ-S00145 航天高级中学 庹恩熙 
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int s,d,f,x,c,v,m=0;
int t,n;
int a[N][4];
int main(){
	freopen("club.in","r",stdin);
	cin>>t;
	for(int e=0;e<t;e++){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n==2){
			s=a[1][1]+a[2][2];
			d=a[1][1]+a[2][3];
			f=a[1][2]+a[2][1];
			x=a[1][2]+a[2][3];
			c=a[1][3]+a[2][1];
			v=a[1][3]+a[2][2];
			m=max(max(max(s,d),max(f,x)),max(c,v));
			cout<<m<<'\n';
			continue;
		}
		cout<<m<<'\n';
	}
	freopen("club.out","w",stdout);
	return 0;
}

