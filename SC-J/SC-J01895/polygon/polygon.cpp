#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans=0;
bool js;
//int mx;
int z;
bool cmp(int c,int p){
	return (c<p);
}
//long long dg(int m){
//	int ansdg;
//	if(m==3) {
//		if(a[m-1]+a[m-2]>a[m]) ans+= 1;
//		else ans+= 0;
//	}
//	else ans+=dg(m-1)+dg(m-2);
//}
void dbx(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				js=false;
				z=0;
				//mx=k;
			//	z=a[i]+a[j]+a[k];
				//cout<<z;//ttttttt
				//cout<<a[i]<<a[j]<<a[k];//TTTTTTTT
				//if(z>2*mx){
				//	ans++;
				//}
				if(a[i]+a[j]>a[k]) ans+=k-j;
				else if(k-j!=1) {
					for(int bs=j;bs<k;bs++){ 
						z+=a[bs];
						if(a[i]+z>a[k]) {
							ans+=k-bs;
							break;
						}
					}
				}
				if(k-j!=1&&js!=1){
					for(int hb=j;hb<k;hb++){
						if(a[hb]+a[i]+a[j]>a[k]) ans++;
					}
				}
				//else if(a[i]+z>a[k]&&k-j!=1) ans++;

			}
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	//for(int i=1;i<=n;i++){
	//	cout<<a[i];
	//}//tttttttttttttttttttttttttt
	if(n==3) {
		if(a[1]+a[2]+a[3]>a[1]*2) cout<<1;
		else cout<<0;
	}
	else dbx();
//	dg(n);
	cout<<ans%998244353;
}