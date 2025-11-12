#define x first
#define y second
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
typedef pair<int,int> PII;
const int N=100010;
int q[3][N],tt[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		for(int j=0;j<3;++j)
			tt[j]=0;
		int n;
		scanf("%d",&n);
		int res=0;
		for(int i=1;i<=n;++i){
			static PII a[5];
			for(int j=0;j<3;++j){
				scanf("%d",&a[j].x);
				a[j].y=j;
			}
			sort(a,a+3);
			res+=a[2].x;
			q[a[2].y][++tt[a[2].y]]=a[1].x-a[2].x;
		}
		for(int j=0;j<3;++j){
			if(tt[j]<=n/2)
				continue;
			sort(q[j]+1,q[j]+1+tt[j]);
			for(int i=n/2+1;i<=tt[j];++i)
				res+=q[j][i];
		}
		printf("%d\n",res);
	}
	return 0;
}