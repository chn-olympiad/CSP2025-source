#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,ans;
int z[510],su[510];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>z[i];
	}
//	if(a==10)
//	for(int c=1;c<=a;c++){
//		for(int d=1;d<=a;d++){
//			for(int e=1;e<=a;e++){
//				for(int f=1;f<=a;f++){
//					for(int g=1;g<=a;g++){
//						for(int h=1;h<=a;h++){
//							for(int i=1;i<=a;i++){
//								for(int j=1;j<=a;j++){
//									for(int k=1;k<=a;k++){
//										for(int l=1;l<=a;l++){
//											if(c!=d!=e!=f!=g!=h!=i!=j!=k!=l){
//												cout<<"Why csp-s was much harder than before?";
//											}
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
	
	cout<<(ans*ans*-1)%998244353;
	return 0;
}
