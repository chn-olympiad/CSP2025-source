#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
int a[N][5],sum,maxx,l[N],d[N],b[N];
int n;
void dfs(int i,int j,int k,int x){
	if(sum+(d[n]-d[x-1])<maxx) return ;
	if(i>n/2) return ;
	if(j>n/2) return ;
	if(k>n/2) return ;
	if(x==n+1){
	    maxx=max(maxx,sum);
	    return ;
	}
	sum+=a[x][1];
	dfs(i+1,j,k,x+1);
	sum-=a[x][1];
	sum+=a[x][2];
	dfs(i,j+1,k,x+1);
	sum-=a[x][2];
	sum+=a[x][3];
	dfs(i,j,k+1,x+1);
	sum-=a[x][3];
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    	int suma=0,sumb=0,sumc=0;
    	for(int i=0;i+5<N;i++){
    		l[i]=d[i]=b[i]=0;
    		for(int j=1;j<=3;j++) a[i][j]=0;
		}
    	sum=0,maxx=-1;
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=3;j++) cin>>a[i][j],l[i]=max(l[i],a[i][j]),d[i]=d[i-1]+l[i];
    		suma+=a[i][1];
    		sumb+=a[i][2];
    		sumc+=a[i][3];
		}
    	if(n<=30){
    		dfs(0,0,0,1);
    		cout<<maxx<<endl;
		}
		else if(sumb==0&&sumc==0){
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1,greater<int>());
			int sumx=0;
			for(int i=1;i<=n/2;i++) sumx+=b[i];
			cout<<sumx<<endl;
		}
	}
	return 0;
}