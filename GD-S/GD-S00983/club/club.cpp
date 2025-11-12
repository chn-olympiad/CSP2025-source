#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005],cnt1,sum;
bool vis[100005];
struct node{
	int a1,a2,num;
}e[100005];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	/*while(t--){
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			int maxn=0,c=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(maxn<a[i][j]) {
					maxn=a[i][j];
					c=j;
				}
			}
			a[i][0]=c;
		}
		for(int i=1;i<=n;i++){
			if(cnt[a[i][0]]<n/2){
				sum+=a[i][a[i][0]];
				cnt[a[i][0]]++;
				vis[i]=1;
			}
			
		}
	}*/
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int b,c;
			cin>>a[i]>>b>>c;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			sum+=a[i];
			cnt1++;
			if(cnt1==n/2) break; 
		}
	}
	cout<<sum;
	return 0;
}
	
