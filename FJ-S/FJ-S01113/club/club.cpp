#include<bits/stdc++.h>
using namespace std;
bool b11,b12;
int t,n,a[100005],b[100005],c[100005],x;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		b11=1,b12=1,x=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a[j],&b[j],&c[j]);
			if(b[j]!=0)b11=0;
		}
		if(b11==1){
			sort(a+1,a+n+1,greater<int>());
			for(int j=1;j<=n/2;j++)x+=a[i];
			printf("%d\n",&x);
		}else{
			int bm1=0,bm2=0;
			for(int j=1;j<=n/2*2;j++){
				if(bm1+1<=n/2&&a[j]>b[j]){
					x+=a[j];
					bm1++;
				}else if(bm2+1<=n/2&&b[j]>a[j]){
					x+=b[j];
					bm2++;
				}else if(bm1+1>n/2){
					x+=b[j];
					bm2++;
				}else if(bm2+1>n/2){
					x+=a[j];
					bm1++;
				}
			}
			printf("%d\n",&x);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//can pian some fen pian some fen
//rp++
