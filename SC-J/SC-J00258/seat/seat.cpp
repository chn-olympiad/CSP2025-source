#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,kl,x,y,num=0;
int b[225];
int qwe(int &n,int &m){return m<n;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&b[i]);
	kl=b[1];
	sort(b+1,b+1+n*m,qwe);
	for(int i=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=n;j++){
				num++;
				if(b[num]==kl){
					x=i,y=j;
					printf("%d %d",x,y);
					return 0;
				}
			}
		else
			for(int j=n;j>=1;j--){
				num++;
				if(b[num]==kl){
					x=i,y=j;
					printf("%d %d",x,y);
					return 0;
				}
			}
	}
	return 0;
}