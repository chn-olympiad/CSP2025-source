#include<bits/stdc++.h> 
using namespace std;
const int N=100005,MOD=998244353;
int n,a[N],ans;
map<string,int>coun;
void solve(int x,int sum,int maxx,int summ,bool pd)
{
	if(sum>2*maxx&&summ>=3&&pd==false)
		ans++,pd=true;
	
	if(x>n)
		return;
	solve(x+1,sum,maxx,summ,pd);
	solve(x+1,sum+a[x],max(maxx,a[x]),summ+1,false);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	
	solve(1,0,0,0,false);
	cout<<ans;
	return 0;
}
