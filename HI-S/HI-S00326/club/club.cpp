#include<bits/stdc++.h>; 
using namespace std;
int t,n,a[3][100005],c[3],d,m,l,g,e,f[200005];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int i;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[0][j]>>a[1][j]>>a[2][j];
			
		}
		sort(a[0],a[0]+n);
		sort(a[1],a[1]+n);
		sort(a[2],a[2]+n);
		for(int j=n-1;j>n/2-1;j--){
			c[0]=c[0]+a[0][j];
			c[1]=c[1]+a[1][j];
			c[2]=c[2]+a[2][j];
		}
		m=max(c[1],c[0]);
		m=max(c[2],m);
		for(int j=0;j<3;j++){
			if(m==c[j]){
				l=j;
				break;
			}
		}
		if(l==0){
			g=2;
			e=1;
		}else if(l==1){
			g=0;
			e=2;
		}else{
			g=0;
			e=1;
		}
		for(int j=0;j<n*2-2;j++){
			f[j]=a[g][j];
			f[n+j]=a[e][j];
		}
		sort(f,f+n*2);
		m=0;
		for(int j=n*2-1;j>(n*2-1-n/2);j--){
			m=m+f[j];
		}
		cout<<c[l]+m;
		c[0]=0;
		c[1]=0;
		c[2]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

