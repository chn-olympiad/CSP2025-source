#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	char c;
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x*=f;
}
inline void write(int x){
	if(x==0) return ;
	if(x<0) putchar('-'),x=-x;
	write(x/10);
	putchar(x%10+48);
	return ;
}
int a[100005];
bool vis[100005];
//bool Vis
int x,seat;
int ans=0;
int n;
void dfs(int step,int sum,int last){
//	cout<<step;
	if(step==seat) return ;
	for(int i=last;i<seat;i++)
	{
		if(!vis[i]){
			if(sum+a[i]>x){
				ans++;
//				cout<<seat<<' ';
			}
			vis[i]=true;
			dfs(step+1,sum+a[i],i+1);
			vis[i]=false;
		}
	}
}
int maxn=-1;
inline int C(int n,int m){
	int cnt=0,sum1=1,sum2=1;
	while(cnt<m){
		cnt++;
		sum1*=n;
		n--;
//		cout<<sum1<<' '; 
	}
	for(int i=m;i>1;i--){
		sum2*=i;
	}
//	cout<<sum1<<' '<<sum2;
	return sum1/sum2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		maxn=max(maxn,a[i]); 
	}
	if(maxn==1){
		for(int i=3;i<=n;i++){
			ans+=C(n,i);
		}
		cout<<ans;
		exit(0);
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		x=a[i];
		seat=i;
		dfs(0,0,1);
	} 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

