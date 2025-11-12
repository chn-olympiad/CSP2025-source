#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int N=5010,Mod=998244353;
struct node{
	int s,mx;
};

int n;
int a[N];
vector<node> f[N][N]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	
	int res=0;
	
	for(int i=2;i<=n;i++){
		f[i][2]=f[i-1][2];
		for(int j=i-1;j>0;j--)f[i][2].push_back({a[i]+a[j],max(a[i],a[j])});
	}
	
	for(int i=3;i<=n;i++){
		for(int j=3;j<=i;j++){
			f[i][j]=f[i-1][j];
			for(int z=0;z<f[i-1][j-1].size();z++){
				int s=f[i-1][j-1][z].s,mx=f[i-1][j-1][z].mx;
				f[i][j].push_back({s+a[i],max(mx*2,mx)});
				if(a[i]+s>max(2*a[i],mx))res=(res+1)%Mod;
			}
		}
	}
		
		
	printf("%d",res);
	return 0;
}
