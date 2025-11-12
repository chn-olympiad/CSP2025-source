#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const unsigned int maxn=5e5+5;
ull k,a[maxn],ans;
bool flag[maxn];
ull fun(ull x,ull y){    //fun(x,0)=x;
	int nx[35],ny[35],t[35],r[35],num=0;
	memset(nx,0,sizeof(nx));
	memset(ny,0,sizeof(ny));
	for(int i=1;(x!=0)||(y!=0);i++)
	{
		nx[i]=x%2; x/=2; num++;
		ny[i]=y%2; y/=2;
//		cout<<nx[i]<<" "<<ny[i]<<endl;
		if(nx[i]!=ny[i]) r[i]=1;
		else r[i]=0;
	}
	ull cnt=0;
	for(int i=num;i>0;i--)
	{
		t[num-i+1]=r[i];
//		cout<<"t["<<num-i+1<<"]:"<<t[num-i+1]<<endl;
		cnt+=t[num-i+1]*pow(2,i-1);
	}
	return cnt;
}
void dfs(){
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int l=1,r=n;l<=n;l++)
	{
		memset(flag,0,sizeof(flag));
		if(a[l]==k&&!flag[l]) ans++,flag[l]=true;
		int temp=0;
		for(int i=l+1;i<=r;i++)
		{
			if(!flag[i]){
				temp=fun(a[i],temp);
				if(temp==k){
					for(int j=l+1;j<=i;j++) flag[j]=true;
					ans++,r=i; break;
				}
			}
			
		}
	}
	cout<<ans<<endl;
	return 0;
}