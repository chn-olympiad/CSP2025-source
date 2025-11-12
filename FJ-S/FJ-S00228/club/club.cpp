#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
struct node{
	int x,id;
	bool operator <(const node p) const{
		return x<p.x;
	}
}a[N][4];
int tot[4];
int b[4][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++){
				cin>>a[i][j].x;
				a[i][j].id=j;
			}
		memset(tot,0,sizeof(tot));
		int ans=0;
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+4);
			tot[a[i][3].id]++;
			ans+=a[i][3].x;
			b[a[i][3].id][tot[a[i][3].id]]=a[i][3].x-a[i][2].x;
		}
		for(int j=1;j<=3;j++) sort(b[j]+1,b[j]+1+tot[j]);
		for(int j=1;j<=3;j++)
			if(tot[j]>n/2){
				for(int i=1;i<=tot[j]-n/2;i++) ans-=b[j][i];
			}
		cout<<ans<<"\n";
	}
	return 0;
}
