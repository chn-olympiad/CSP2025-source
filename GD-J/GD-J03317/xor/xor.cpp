#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int n,k;
int x[500010],a[500010],f[500010][3]; 
int xo(int x,int y){
	int t=0,a=x,b=y,z=1;
	while(a||b){
		if(a%2+b%2==1){
			t+=z; 
		}
		z*=2,a/=2,b/=2;
	}
	return t;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int cnt=a[i],j;
		for(j=i-1;j>0;j--){
			if(cnt==k) break;
			cnt=xo(cnt,a[j]); 
		}
		if(cnt==k) x[i]=j+1;
		else x[i]=-1;
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		if(x[i]>0 && f[x[i]][0]+1>f[i][0]) f[i][1]=f[x[i]][0]+1;
		else f[i][1]=f[i][0];
	} 
	cout<<max(f[n][1],f[n][0])<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
