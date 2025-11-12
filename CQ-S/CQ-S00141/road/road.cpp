#include <bits/stdc++.h>
using namespace std;
struct A{
	int c1,c2,q,jz;
}a[1000005],c[12][10005],mii[10005];
struct B{
	int z,q;
}mi[10005];

int f[10005];
long long num;
bool mm(A x,A y){
	return x.q<y.q;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ji=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].c1>>a[i].c2>>a[i].q;
	} 
	sort(a+1,a+1+m,mm);
	int flg=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			if(j!=0) {
				cin>>c[i][j].q;
				if(c[i][j].q!=0) flg=1;
			}
			else cin>>c[i][j].jz;
		}
	}
	if(flg==0) {
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(f[a[i].c1]<2||f[a[i].c2]<2){
			num+=a[i].q;
			f[a[i].c1]++;
			f[a[i].c2]++;
			if(f[a[i].c1]==2) ji++;
			if(f[a[i].c2]==2) ji++;
			if(ji>=n-2) {
				cout<<num;
				return 0;
			}
		}
	}
	cout<<num;
//		if(f==1){
//			for(int j=1;j<=k;j++){
//				for(int z=1;z<=n;z++){
//					
//				}
//			}
//		}
		
	 
	
	return 0;
} 
