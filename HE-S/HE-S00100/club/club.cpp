#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+100;
int t,a[N][5],b[N][5];
int maa,mii;
int ma[N],mi[N],zj[N];//最大 最小 中间 
int x[N],y[N],z[N];//最大的下标 中间的下标 最小的下标 
int ch[N];
int h[N],j[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
		memset(z,0,sizeof z);
		int n,anss=0;
		cin>>n;
		int q=n/2;
		int cnt=0,ans=0,sum=0;//计数
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			maa=INT_MIN;
		 	for(int j=1;j<=3;j++){
		 		maa=max(maa,a[i][j]);
			}
			ma[i]=maa;
		}
		for(int i=1;i<=n;i++){
			mii=INT_MAX;
		 	for(int j=1;j<=3;j++){
		 		mii=min(mii,a[i][j]);
			}
			mi[i]=mii;
		}
		for(int i=1;i<=n;i++){
			if(ma[i]==a[i][1]){
				x[i]=1;
			}
			else if(ma[i]==a[i][2]){
				y[i]=1;
			}
			else if(ma[i]==a[i][3]){
				z[i]=1;
			}
			if(mi[i]==a[i][1]){
				x[i]=3;
			}
			else if(mi[i]==a[i][2]){
				y[i]=3;
			}
			else if(mi[i]==a[i][3]){
				z[i]=3;
			} 
		}
		for(int i=1;i<=n;i++){
			if(x[i]==0){
				x[i]=2;
			}
			else if(y[i]==0){
				y[i]=2;
			}
			else if(z[i]==0){
				z[i]=2;
			}
		}
		for(int i=1;i<=n;i++){
			b[i][1]=ma[i];
			b[i][3]=mi[i];
			if(x[i]==2){
				b[i][2]=a[i][1];
			}
			else if(y[i]==2){
				b[i][2]=a[i][2];
			}
			else if(z[i]==2){
				b[i][2]=a[i][3];
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				cout<<b[i][j]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<endl;
		for(int i=1;i<=n;i++){
			anss+=ma[i];
		}
		for(int i=1;i<=n;i++){
			if(x[i]==1){
				cnt++;
			} 
			else if(x[i]==2){
				ans++;
			}
			else if(x[i]==3){
				sum++;
			}
		}
		if(cnt>q){
			int o=0;
			for(int i=1;i<=n;i++){
				if(x[i]==1){
					o++;
					h[o]=b[i][1];
					j[o]=b[i][2];
				}
			}
			for(int i=1;i<=o;i++){
				ch[i]=h[i]-j[i];
			}
			sort(ch+1,ch+1+o);
			int y=cnt-q;
			for(int i=1;i<=y;i++){
				anss-=ch[i];
			}
		}
		else if(ans>q){
			int o=0;
			for(int i=1;i<=n;i++){
				if(x[i]==2){
					o++;
					h[o]=b[i][1];
					j[o]=b[i][2];
				}
			}
			for(int i=1;i<=o;i++){
				ch[i]=h[i]-j[i];
			}
			sort(ch+1,ch+1+o);
			int y=ans-q;
			for(int i=1;i<=y;i++){
				anss-=ch[i];
			}
		}
		else if(sum>q){
			int o=0;
			for(int i=1;i<=n;i++){
				if(x[i]==3){
					o++;
					h[o]=b[i][1];
					j[o]=b[i][2];
				}
			}
			for(int i=1;i<=o;i++){
				ch[i]=h[i]-j[i];
			}
			sort(ch+1,ch+1+o);
			int y=sum-q;
			for(int i=1;i<=y;i++){
				anss-=ch[i];
			}
		}
		cout<<anss<<endl;
	}
	return 0;
}
