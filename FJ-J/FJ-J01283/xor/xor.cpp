#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],f[N];
int t[2000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<(1<<20);i++) t[i]=-1;
	t[k]=0;
	int ans=0,now=0;
	for(int i=1;i<=n;i++)
	{
		int s=0;
		f[i]=f[i-1];
		for(int j=0;j<20;j++)
		{
			int x=((a[i]>>j)&1),y=((now>>j)&1);
//			cout << j << " " <<x<< " " << y <<endl;
			s+=(1<<j)*((x+y)%2); 
		}
		now=s;
//		cout <<now << " ";
		if(t[now]!=-1) f[i]=max(f[i],f[t[now]]+1);
//		cout << f[i] << endl; 
		ans=max(ans,f[i]);
		s=0;
		for(int j=0;j<20;j++)
		{
			int x=((k>>j)&1),y=((now>>j)&1);
//			cout << j << " " <<x<< " " << y <<endl;
			s+=(1<<j)*((x+y)%2);
		}
		t[s]=i;
	}
	cout << ans;	
	return 0;
} 
