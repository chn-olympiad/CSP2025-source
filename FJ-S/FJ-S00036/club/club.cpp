#include<bits/stdc++.h>
using namespace std;
long long int n,m,t,aa,bb,cc;
long long int a[10001],b[10001],c[10001],num,aj[1001],bj[1001],cj[1001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		aa=0;
		bb=0;
		cc=0; 
		cin>>m;
		t=m/2;
		for(int j=1;j<=m;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		for(int j=1;j<m;j++){
			if(a[j]>b[j]&&a[j]>c[j]){
				num+=a[j];
//				if(aa==t){
//					if(b[j]>c[j]&&bb<t){
//						bb++;
//					}else if(c[j]>b[j]&&cc<t){
//						cc++;
//					}
//				}else{
//					aa++;
//				}
				
			}else if(b[j]>a[j]&&b[j]>c[j]){
				num+=b[j];
//				if(bb==t){
//					if(a[j]>c[j]&&aa<t){
//						aa++;
//					}else if(c[j]>a[j]&&cc<t){
//						cc++;
//					}
//				}else{
//					bb++;
//				}
			}else if(c[j]>a[j]&&c[j]>b[j]){
				num+=c[j];
//				if(cc==t){
//					if(a[j]>b[j]&&aa<t){
//						aa++;
//					}else if(b[j]>a[j]&&bb<t){
//						bb++;
//					}
//				}else{
//					cc++;
//				}
			}
		}
//		for(int j=1;j<=m;j++){
//			for(int k=1;k<=m;k++){
//				if(b[k+1]>b[k]){
//					int u1,u2,u3;
//					u2 = b[j];
//					b[j] = b[j+1];
//					b[j+1] = u2;
//				}
//				if(a[k+1]>a[k]){
//					int u1,u2,u3;
//					u1 = a[j];
//					a[j] = a[j+1];
//					a[j+1] = u1;
//				}
//				if(c[k+1]>c[k]){
//					int u1,u2,u3;
//					u1 = c[j];
//					c[j] = c[j+1];
//					c[j+1] = u1;
//				}
//			}
//		}
//		for(int j=1;j<=aa;j++){
//			num+=a[j];
//		}
//		for(int j=1;j<=bb;j++){
//			num+=b[j];
//		}
//		for(int j=1;j<=cc;j++){
//			num+=c[j];
//		}
		cout<<num<<endl;
		num=0;
	}
	return 0;
} 
