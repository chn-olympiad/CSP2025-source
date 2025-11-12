#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int T;
//int f[MAXN][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int ans=0;
		if(n<=4){
			for(int i=1;i<=n;i++){
				int a1,a2,a3;
				cin>>a1>>a2>>a3;
				int maxn=max(max(a1,a2),a3);
				ans+=maxn;
			}
			cout<<ans<<endl;
		}else{
			int a[MAXN][5]={0};
		int to=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			/*f[i][1]=a[i][1];
			f[i][2]=a[i][2];
			f[i][2]=a[i][2];*/
		}
		for(int i=2;i<=n;i++){
			int num[5]={0};
			for(int j=1;j<=3;j++){
				if(num[j]>=to){//超出社团限制 
					a[i][j]=a[i-1][j-1];
					continue;
				}
				a[i][j]=max(max(a[i][j],a[i][j-1]+a[i][j]),a[i-1][j]+a[i][j]);
				num[j]++;
			}
		}
		cout<<a[n][3]<<endl;
		}
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
*/
