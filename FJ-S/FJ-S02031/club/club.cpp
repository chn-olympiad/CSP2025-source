#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,a[N][3],ans=INT_MIN,max1=INT_MIN,cnt1,cnt2;
bool b[3];
//pair<int,int> f[N][4];
void dfs(int i,int w,int c1,int c2,int c3){
//	cout<<i<<" "<<w<<" "<<c1<<" "<<c2<<" "<<c3<<endl;
	if(i>n){
		ans=max(ans,w);
//		cout<<ans<<endl;
		return;
	}
	if(c1<n/2){
		dfs(i+1,w+a[i][1],c1+1,c2,c3);	
	}	
	if(c2<n/2){
		dfs(i+1,w+a[i][2],c1,c2+1,c3);	
	}
	if(c3<n/2){
		dfs(i+1,w+a[i][3],c1,c2,c3+1);	
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		max1=ans=INT_MIN;
		cnt1=cnt2=0;
		b[1]=b[2]=b[3]=true;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				f[i][j]={0,0};
//			}
//		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0)b[1]=false;
			if(a[i][3]!=0)b[2]=false;
			max1=max(max1,a[i][1]);
		}
		if(b[2]){
			if(b[1]){
				cout<<max1<<endl;
			}else{
				ans=0;
				for(int i=1;i<=n;i++){
					if(cnt1>=n/2){
						ans+=a[i][2];
						cnt2++;
					}else if(cnt2>=n/2){
						ans+=a[i][1];
						cnt1++;
					}else if(a[i][1]>a[i][2]){
						ans+=a[i][1];
						cnt1++;
					}else{
						ans+=a[i][2];
						cnt2++;
					}
				}
				cout<<ans<<endl;
			}
		}else{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				if(f[i-1][j].first>=n/2)f[i][j].second=f[i-1][j].second;
//				else f[i][j]={f[i-1][j].first+1,max(f[i][j].second,f[i-1][j].second+a[i][j])};
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				cout<<f[i][j].second<<" ";
//			}cout<<endl;
//		}
	}
}
