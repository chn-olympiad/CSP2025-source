#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+5;
struct nu{
	int m,b;
};
nu a[5][N];
bool vis[N];
int cmp(nu t,nu y){
	return t.m>y.m;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			vis[i]=false;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j][i].m;
				a[j][i].b=i;
			}
		}
		for(int i=1;i<=3;i++){
			sort(a[i]+1,a[i]+n+1,cmp);
		}

		int w=1,oiu=0;//now which club wo do at,and how much perso now
		int iop=0;//How many pepole we have;
		int sum=0; //the all mayidu;
		int n1=1,n2=1,n3=1;
		int sum1=0,sum2=0;
		while(iop<n){
/*			while(vis[a[1][n1].b])n1++;
			while(vis[a[2][n2].b])n2++;
			while(vis[a[3][n3].b])n3++;*/

			int x=a[1][n1].m,y=a[2][n2].m,k=a[3][n3].m;
			bool xc,yc;
			int maxn=x+y+k;
			if(sum1<n/2&&vis[a[1][n1].b]==false)xc=true;
			else xc=false;

			if(sum2<n/2&&vis[a[2][n2].b]==false)yc=true;
			else yc=false;

			if(x==maxn&&xc){
				w=1;oiu=n1;n1++;sum1++;
			}else{
				if(y>k&&yc){
					w=2;oiu=n2;n2++;sum2++;
				}else{
					w=3;oiu=n3;n3++;
				}
			}
			sum+=a[w][oiu].m;
			vis[a[w][oiu].b]=true;
			iop++;

		}
		cout<<sum<<endl;
		t--;
	}
	return 0;
}
//Z-9
//Zhao
