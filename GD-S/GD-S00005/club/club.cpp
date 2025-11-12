#include<bits/stdc++.h>
using namespace std;
int t,n;
#define x first
#define y second
const int N=1e5+10;
typedef long long ll;
ll d[4][N],res,c[4];
typedef pair<int,int> PII;
PII a[4];
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		memset(d,0,sizeof d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j].x;
				a[j].y=j;
			}
			sort(a+1,a+1+3);
			d[a[3].y][++d[a[3].y][0]]=a[3].x-a[2].x;
			res+=a[3].x;
		}
		for(int i=1;i<=3;i++){
			if(d[i][0]>n/2){
				int dif=d[i][0]-n/2;
				sort(d[i]+1,d[i]+1+d[i][0]);
				for(int j=1;j<=dif;j++)res-=d[i][j];
			}
		}
		cout<<res<<endl;
	}
	return 0; 
} 
