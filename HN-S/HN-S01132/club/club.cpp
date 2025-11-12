#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,c[5],a[N][5];
long long ans=-1,cnt,ans2,ans3,cnt1,cnt2;
bool vis[N][5];
//struct nd{
//	int a,b,c;
//}k[N];
//bool cmp(nd x,nd y){
//	if(x.a==y.a) return x.b<y.b;
//	return x.a<y.a;
//}
void dfs(long long sum,int x){
	if(x>=n){
		//cout<<66666<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<sum<<endl;
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[x][i]==0){
			vis[x][i]=1;
			if(c[i]<n/2){
				cnt++;
				c[i]++; 
				//sum+=a[x][i];
				//x++;
				dfs(sum+a[x][i],x+1);
				//x--;
				//sum-=a[x][i];
				c[i]--;
			}
			vis[x][i]=0;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cnt=0;
		for(int i=1;i<=3;i++) c[i]=0;
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=1;j<=3;j++){
				vis[i][j]=0;
				cin>>a[i][j];
//				if(j==1) k[i].a=a[i][j];
//				else if(j==2) k[i].b=a[i][j];
//				else if(j==3) k[i].c=a[i][j];
			}
		}
		//sort(a+1,a+n+1,cmp);
		//if(n<=30){
			dfs(0,0);
			cout<<ans<<endl;
//		}else{
//			for(int i=n;i>=n/2;i--){
//				ans2+=k[i].a;
//			}
//			for(int i=1;i<=n;i++){
//				if(k[i].a>=k[i].b&&cnt1<n/2){
//					cnt1++;
//					ans3+=k[i].a;
//				}else if(k[i].a<k[i].b&&cnt2<n/2){
//					cnt2++;
//					ans3+=k[i].b;
//				}
//			}
//			cout<<max(ans2,ans3);
//		}
		//cout<<"666666666666666666 "<<ans<<endl; 
	}
	return 0;
} 
/*
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
