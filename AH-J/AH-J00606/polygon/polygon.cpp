#include<bits/stdc++.h>
using namespace std;
int c[5010],t[5010],d[5010][5010],len[5010];
const int Mod=998244353;
long long ans=0;
void dfs(int step,int h,int sum){
	if(sum>c[h]){
		long long x=1;
		for(int i=1;i<=len[h]-step+1;i++){
			x*=2;
			x%=Mod;
		}
		ans+=x;
		ans%=Mod;
		return ;
	}
	if(step==len[h]+1)
		return ;
	dfs(step+1,h,sum);
	if(d[h][step]==0)
		return ;
	dfs(step+1,h,sum+d[h][step]);
}
int f[25],n;
void dfs2(int step){
	if(step==n+1){
		int sum=0,Max=0;
		for(int i=1;i<=n;i++){
			if(f[i]){
				sum+=c[i];
				Max=max(Max,c[i]);
			}
		}
		if(sum>Max*2)
			ans++;
		return ;
	}
	f[step]=1;
	dfs2(step+1);
	f[step]=0;
	dfs2(step+1);
}
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int Max2=0;
	for(int i=1;i<=n;i++)
		Max2=max(Max2,c[i]);
	sort(c+1,c+1+n);
	if(Max2<=1){
		if(Max2==0)
			cout<<0;
		else{
			for(int i=1;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					long long x=1;
					for(int a=1;a<=n-j;a++){
						x*=2;
						x%=Mod;
					}
					ans+=x;
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<i;j++){
			sum+=c[j];
			d[i][++len[i]]=c[j];
		}
		if(sum<=c[i])
			t[i]=0;
		else
			t[i]=1;
	}
	for(int i=1;i<=n;i++)
		sort(d[i]+1,d[i]+1+len[i],cmp);
	if(n<=20){
		ans=0;
		dfs2(1);
		cout<<ans<<endl;
		return 0;
	}
	else{
		ans=0;
		for(int i=1;i<=n;i++){
			if(t[i])
				dfs(1,i,0);
			//cout<<ans<<endl;
		}
		cout<<ans;
	}
	return 0;
}
//I want to have 80pts
//I think I can do it
//Bro,who can tell me how many pts can I have?
//80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 

//80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 

//80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 80! 

