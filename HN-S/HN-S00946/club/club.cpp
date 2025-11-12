#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const int s=210;
int t;
int n,m,up;
int a[s][5],f[s][s][s],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=-1e9;
		memset(f,0,sizeof(f));
		
		scanf("%d",&n);
		up=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			//f[i][1]=a[i][1];f[i][2]=a[i][2];f[i][3]=a[i][3];
		}
		//cout<<"endl"<<endl;
		for(int i=1;i<=n;i++){
			//cout<<i<<endl;
			for(int n1=min(up,i);n1>=0;n1--){
				for(int n2=min(up,n-n1);n2>=0;n2--){//1
					for(int n3=min(up,n-n1-n2);n3>=0;n3--){//2
						if(n1+n2+n3>n)continue;
						if(n1!=0)f[n1][n2][n3]=max(f[n1][n2][n3],f[n1-1][n2][n3]+a[i][1]);
						if(n2!=0)f[n1][n2][n3]=max(f[n1][n2][n3],f[n1][n2-1][n3]+a[i][2]);
						if(n3!=0)f[n1][n2][n3]=max(f[n1][n2][n3],f[n1][n2][n3-1]+a[i][3]);
						//cout<<n1<<' '<<n2<<' '<<n3<<' '<<f[n1][n2][n3]<<endl;
						ans=max(ans,f[n1][n2][n3]);
					}
				}
			}
			//cout<<endl;		
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
