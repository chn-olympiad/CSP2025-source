#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100005][5],b[100005],c[100005];
ll sum;
bool cmp(ll l,ll r){
	return l<r;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(c,0x3f3f3f3f,sizeof(c));
		int id=0,sum=0;
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ll maxn=max(max(a[i][1],a[i][2]),a[i][3]);
			sum+=maxn;
			if(maxn==a[i][1]){
				cnt1++;
				b[i]=1;
			}
			else if(maxn==a[i][2]){
				cnt2++;
				b[i]=2;
			}
			else if(maxn==a[i][3]){
				cnt3++;
				b[i]=3;
			}
		}
		if(cnt1*2>n) id=1;
		else if(cnt2*2>n) id=2;
		else if(cnt3*2>n) id=3;
		if(id==0){
			cout<<sum<<'\n';
			continue;
		}
		else if(id==1){
			//cout<<cnt1<<'\n';
			int tot=0;
			for(int i=1;i<=n;i++){
				if(b[i]!=1) continue;
				tot++;
				for(int j=2;j<=3;j++){
					c[tot]=min(c[tot],a[i][1]-a[i][j]);
				}
				//cout<<c[tot]<<'\n';
			}
			//cout<<tot<<'\n';
			sort(c+1,c+tot+1,cmp);
			for(int i=1;i<=cnt1-n/2;i++){
				sum-=c[i];
				//cout<<"1 "<<c[i]<<'\n';
			}
			cout<<sum<<'\n';
			continue;
		}
		else if(id==2){
			int tot=0;
			for(int i=1;i<=n;i++){
				if(b[i]!=2) continue;
				tot++;
				for(int j=1;j<=3;j++){
					if(j==2) continue;
					c[tot]=min(c[tot],a[i][2]-a[i][j]);
				}
				//cout<<c[tot]<<' ';
			}
			sort(c+1,c+tot+1,cmp);
			for(int i=1;i<=cnt2-n/2;i++){
				sum-=c[i];
				//cout<<"2 "<<c[i]<<'\n';
			}
			cout<<sum<<'\n';
			continue;
		}
		else if(id==3){
			int tot=0;
			for(int i=1;i<=n;i++){
				if(b[i]!=3) continue;
				tot++;
				for(int j=1;j<=2;j++){
					c[tot]=min(c[tot],a[i][3]-a[i][j]);
				}
				//cout<<c[tot]<<' ';
			}
			sort(c+1,c+tot+1,cmp);
			for(int i=1;i<=cnt3-n/2;i++){
				sum-=c[i];
				//cout<<"3 "<<c[i]<<'\n';
			}
			cout<<sum<<'\n';
			continue;
		}
	}
	return 0;
}
