#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5005];
bool chk(int x,int y,int z){
	if(x+y>z&&x+z>y&&z+y>x&&x-y<z&&x-z<y&&y-z<x&&y-x<z&&y-z<x&&z-y<x)return true;
	return false;
}
int QC(){
	int f[5005]={0},cnt;
	for(int i=1;i<=n;i++)f[a[i]]++;
	for(int i=1;i<=5000;i++)if(f[i]>1)cnt+=f[i];
	return cnt;
}
void solve1(){
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(chk(a[i],a[j],a[k]))ans++;
	for(int i=4;i<=n;i++){
		int cnt=1;
		for(int j=1;j<=i;j++)cnt*=n-j+1;
		for(int j=1;j<=i;j++)cnt/=j;
		ans+=cnt;
	}
	ans%=N,ans-=QC();
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3)cout<<0;
	else if(n==3){
		if(chk(a[1],a[2],a[3]))cout<<1;
		else cout<<0;
	}
	else if(n<=20){
		solve1();
	}
	return 0;
}
