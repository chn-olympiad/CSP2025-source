#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int t,n,cnt[4],v;
ll f[N][4],ans;
struct node{
	int x,y,z;
}a[N];
void fun(int i){
	if(i>n){
		ans=max(ans,max(max(f[n][1],f[n][2]),f[n][3]));return;
	}
	for(int j=1;j<=3;j++){
		if(j==1) v=a[i].x;
		else if(j==2) v=a[i].y;
		else v=a[i].z;
		if(cnt[j]==(n/2)) continue;
		f[i][j]=max(f[i-1][1],max(f[i-1][2],f[i-1][3]))+v;
		cnt[j]++;
		fun(i+1);
		cnt[j]--;
		f[i][j]=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		fun(1);
		cout<<ans<<'\n';
	}
	return 0;
}
