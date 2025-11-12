#include<cstdio>
#include<algorithm>

using namespace std;

int T;

const int N=1e5+5;

int n,a[N][3];

int d[3][N],d1[3];

int Ans;

void Solve(){
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=0;j<3;j++){
		scanf("%d",&a[i][j]);
	}
	
	Ans=0;d1[0]=d1[1]=d1[2]=0;
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			Ans+=a[i][0];
			d[0][++d1[0]]=a[i][0]-max(a[i][1],a[i][2]);
		}
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			Ans+=a[i][1];
			d[1][++d1[1]]=a[i][1]-max(a[i][0],a[i][2]);
		}
		else{
			Ans+=a[i][2];
			d[2][++d1[2]]=a[i][2]-max(a[i][0],a[i][1]);
		}
	}
	
	for(int j=0;j<3;j++){
		if(d1[j]>n/2){
			sort(d[j]+1,d[j]+d1[j]+1);
			for(int i=1;i<=d1[j]-n/2;i++){
				Ans-=d[j][i];
			}
		}
	}
	
	printf("%d\n",Ans);
	
	return;
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--)Solve();
	
	return 0;
}
