#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,a[5005],ans,m=998244353,cnt,mm,cnt2;
bool cmp(int x,int y){
	return x<y;
}
void dfs(int c)
{
	//判断c是否越界n
	if(c>n)return; 
	//1.选择 
	cnt+=a[c];
	cnt2++;
	int nn=mm;
	mm=a[c];
	//判断选当前能否成立
	if(cnt2>=3){
		if(cnt>mm*2)ans=(ans+1)%m;
	} 
	dfs(c+1);
	//2.不选
	cnt-=a[c];
	cnt2--;
	mm=nn;
	dfs(c+1);
	 
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	dfs(1);
	cout<<ans;
	return 0;
}
