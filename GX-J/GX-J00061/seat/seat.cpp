#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[10001];
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
    }
    int b=a[1],j=0;
    sort(a+1,a+1+m*n);
    for(int i=m*n;i>=1;i--){
		j++;
		if(b==a[i]){
			break;
	    }
    }
    int g=0;
    int u=j/m;
    g=u,j-=u*m;
    int d[m],f[m];
    for(int i=1;i<=m;i++){
		d[i]=i;
		f[i]=m+1-i;
    }
    int r=0,z=0;
    if(j==0){
		g=g;
    }else{
		g=g+1;
	}
    r=g;
    if(g%2==0){
		z=f[m-j];
    }else{
		if(j==0){
			z=d[m];
	    }else{
			z=d[j];
	    }
    }
    cout<<r<<" "<<z;
    return 0;
}  
