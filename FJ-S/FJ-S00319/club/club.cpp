#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
int a[N],b[N],c[N];
int f[N][5];
//int fa[N],fb[N],fc[N];
//int k1=1,k2=1,k3=1;
bool f1=false,f2=false;
long long ans;
void check1(){
	for(int i=1;i<=n/2;i++){
		ans+=a[i];
	}
	return;
}
void check2(){
	for(int i=1;i<=n/2;i++){
		if(a[i]+b[n-i+1]<b[i]+a[n-i+1]) {
			ans+=(b[i]+a[n-i+1]);
		}
		else {
			ans+=(a[i]+b[n-i+1]);
		}
	}
	return;
}
void check3(){
	for(int i=1;i<=n;i++){
		ans+=max(a[i],b[i]);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		f1=true;
		f2=true;
		ans=0;
		//k1=k2=k3=1;
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(c));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0 or c[i]!=0) f1=false;
			if(c[i]!=0) f2=false;
			f[i][1]=1,f[i][2]=2,f[i][3]=3;
			if(a[i]<b[i]) {
				swap(a[i],b[i]);
				swap(f[i][1],f[i][2]);
			}
			if(b[i]<c[i]) {
				swap(b[i],c[i]);
				swap(f[i][2],f[i][3]);
			}
			if(a[i]<b[i]) {
				swap(a[i],b[i]);
				swap(f[i][1],f[i][2]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(a[i]>a[j]) {
					swap(a[i],a[j]);
					swap(f[i][1],f[j][1]);
					swap(b[i],b[j]);
					swap(f[i][2],f[j][2]);
				}
				if(a[i]==a[j] and b[i]>b[j]) {
					swap(b[i],b[j]);
					swap(f[i][1],f[j][1]);
					swap(f[i][2],f[j][2]);
				}
			}
		}
		if(f1==true) {
			check1();
		}
		if(f2==true and f1==false){
			check2();
		}
		if(f1==false and f2==false) {
			check3();
		}
		/*
		int g[5][5];
		for(int i=1;i<=n/2;i++){
			g[1][0]=a[i]+a[n-i+1],g[1][1]=f[i][1],g[1][2]=f[n-i+1][1];
			g[2][0]=b[i]+a[n-i+1],g[2][1]=f[i][2],g[2][2]=f[n-i+1][1];
			g[3][0]=a[i]+b[n-i+1],g[3][1]=f[i][1],g[3][2]=f[n-i+1][2];
			g[4][0]=b[i]+b[n-i+1],g[4][1]=f[i][2],g[4][2]=f[n-i+1][2];
			if(g[1][0]>g[2][0] and g[1][0]>g[3][0] and g[1][0]>g[4][0]) {
				if((g[1][1]!=g[1][2] and a1[g[1][1]]+1<=n/2 and a1[g[1][2]]+1<=n/2) or (g[1][1]==g[1][2] and a1[g[1][1]]+2<=n/2)){
					ans+=g[1][0];
					a1[g[1][1]]+=1;
					a1[g[1][2]]+=1;
				}
			}
		}
		*/
		cout<<ans<<endl;
		/*
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" "<<b[i]<<endl;
		}cout<<endl;
		*/
	}
	return 0;
}

