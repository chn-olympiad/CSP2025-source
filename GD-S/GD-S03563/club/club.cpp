#include<bits/stdc++.h>
using namespace std;
int t,n,a[3][100001],maxn,sum[3];
struct STU{
	int maxx,id;
}d[100001],c[100001];
bool cmp(STU A,STU B){
	return A.maxx<B.maxx;
}
void bfs(int T,int I1,int I2,int I3){
	if(I1+I2+I3==n){
		maxn=max(maxn,T);
		return ;
	}
	if(I1==n/2){
		for(int i=I1+I2+I3+1;i<=n;i++)
			T=T+max(a[1][i],a[2][i]);
		maxn=max(maxn,T);
		return;
	}
	else if(I2==n/2){
		for(int i=I1+I2+I3+1;i<=n;i++)
			T=T+max(a[0][i],a[2][i]);
		maxn=max(maxn,T);
		return;
	}
	else if(I3==n/2){
		for(int i=I1+I2+I3+1;i<=n;i++)
			T=T+max(a[0][i],a[1][i]);
		maxn=max(maxn,T);
		return;
	}
	else{
		bfs(T+a[0][I1+I2+I3+1],I1+1,I2,I3);
		bfs(T+a[1][I1+I2+I3+1],I1,I2+1,I3);
		bfs(T+a[2][I1+I2+I3+1],I1,I2,I3+1);
		return ;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			c[i].maxx=a[0][i]-a[1][i];
			c[i].id=i;
			d[i].maxx=max(a[0][i],max(a[1][i],a[2][i]));
			if(a[0][i]>a[1][i]){
				if(a[0][i]>a[2][i]){
					d[i].id=0;
					sum[0]++;
				}
				else{
					d[i].id=2;
					sum[2]++;
				}
			}
			else{
				if(a[1][i]>a[2][i]){
					d[i].id=1;
					sum[1]++;
				}
				else{
					d[i].id=2;
					sum[2]++;
				}
			}
		}
		//if(n==2)maxn=max()
		sort(c+1,c+n+1,cmp);
		sort(d+1,d+n+1,cmp);
		//for(int i=1;i<=n;i++)cout<<c[i].maxx<<endl;
		if(max(sum[0],max(sum[1],sum[2]))<=n/2){
			for(int i=1;i<=n;i++)maxn=maxn+d[i].maxx;
		}
		else if(a[2][1]==0&&a[2][2]==0){
			
			if(a[1][2]!=0||a[1][1]!=0){
				for(int i=1;i<=n;i++)maxn=maxn+a[0][i];
				for(int i=1;i<=n/2;i++)maxn=maxn-c[i].maxx;
			}
			else for(int i=n/2;i<=n;i++)maxn=maxn+d[i].maxx;
		}
		else bfs(0,0,0,0);
		cout<<maxn<<endl;
	}
	return 0;
}
