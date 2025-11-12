#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100010][4];
int b[100010][4],c[4];
struct stu{
	int a;
};
priority_queue<stu>q;
operator < (stu x,stu y){
	return a[x.a][3]-a[x.a][2]>a[y.a][3]-a[y.a][2];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		int max2=0,ans=0;
		for(int i=1;i<=n;i++){
			int maxn=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>=a[i][maxn])maxn=j;
			}
			b[++c[maxn]][maxn]=i;
			ans+=a[i][maxn];
			if(c[maxn]>=c[max2])max2=maxn;
			sort(a[i]+1,a[i]+1+3); 
		}
		for(int i=1;i<=c[max2];i++){
			q.push({b[i][max2]});
		}
		while(q.size()>n/2){
			stu t=q.top();
			ans-=a[t.a][3]-a[t.a][2];
			q.pop();
		}
		cout<<ans<<"\n";
		while(!q.empty()){
			q.pop();
		}
	}
	return 0;
}

