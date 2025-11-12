#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	const int maxn = 2e4+9;
	int t;
	for(int i=1;i<=t;i++){
		int n;
		int a[maxn],b[maxn],c[maxn];
		int mxab[maxn],mxbc[maxn],mxac[maxn],mx[maxn],mxg[maxn];
		int asa=0,asb=0,asc=0,ans=0;
		cin>>n;
		for(int j=1;j<=n;i++){
			cin>>a[j]>>b[j]>>c[j];
			mxab[j] = max(a[j],b[j]);
			mxac[j] = max(a[j],c[j]);
			mxbc[j] = max(b[j],c[j]);
			mx[j] = max(mxab[j],c[j]);
		}
		for(int j=1;j<=n;j++){
			if(mx[j] == a[j]){
				if(asa<=2){
					asa++;
					ans += a[j];
				}
				else{
					if(mxg[j] == b[j]){
						if(asb<2){
							asb++;
							ans+=b[j];				
						}
						else{
							asc++;
							ans += c[j];
						}
					}
					else{
						asc++;
						ans += c[j];
					}
				}
			}
			else if(mx[j] == b[j]){
				if(asb<=2){
					asb++;
					ans += b[j];
				}
				else{
					if(mxg[j] == a[j]){
						if(asa<2){
							asa++;
							ans+=a[j];				
						}
						else{
							asc++;
							ans += c[j];
						}
					}
					else{
						asc++;
						ans += c[j];
					}
				}
			}
			else {
				if(asc<=2){
					asc++;
					ans += c[j];
				}
				else{
					if(mxg[j] == a[j]){
						if(asa<2){
							asa++;
							ans += a[j];				
						}
						else{
							asb++;
							ans += b[j];
						}
					}
					else{
						asb++;
						ans += b[j];
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
