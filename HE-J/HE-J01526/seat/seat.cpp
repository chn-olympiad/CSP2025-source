#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000];
int z[20][20];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++)scanf("%d",&a[i]);
	int s1=a[1],cnt=0;
	sort(a+1,a+1+n*m);
	for(int i=0;i<m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				z[i][j]=a[n*m-j+1-n*cnt];
			}
		}
		if(i%2==0){
			for(int j=1;j>=1;j--){
				z[i][j]=a[n*m-j+1-n*cnt];
				cnt++;
			}
		}
	}
}
