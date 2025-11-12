#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[114514][5];
int cnt[5];
void kd(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	kd();
	int T;
	cin>>T;
	while(T--){
		memset(cnt,0,sizeof(cnt));
		int n;
		cin>>n;
		bool f=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if((j==2||j==3)&&a[i][j]!=0)f=1;
			}
		}
		int ans=0;
		if(!f){
			int hh[114514];
			for(int i=1;i<=n;i++){
				hh[i]=a[i][1];
			}
			sort(hh+1,hh+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=hh[i];
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			int maxx=INT_MIN;
			int x,y;
			for(int j=1;j<=n;j++){
				for(int k=1;k<=3;k++){
					if(a[j][k]>maxx){
						maxx=a[j][k];
						x=j,y=k;
					}
				}
			}
			if(cnt[y]>=n/2){
				for(int j=1;j<=n;j++){
					a[j][y]=-1;
				}
				i--;
				continue;
			}
			ans+=a[x][y];
			cnt[y]++;
			for(int j=1;j<=3;j++){
				a[x][j]=-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

