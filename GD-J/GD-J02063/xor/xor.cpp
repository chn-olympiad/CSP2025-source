#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=5e6+5;
long long n,k,a[N],ans,sum,x,m;
struct c{
	long long st,ed;
}q[M];
long long z[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		x=k^a[i];
		if(x==0){
			q[++m].st=i,q[m].ed=i,++z[i];
			continue;
		} 
		for(int j=i+1;j<=n;j++)
		{
			x^=a[j];
			if(x==0) {
				q[++m].st=i,q[m].ed=j,++z[j];
				break;
			}
		}
	}
	int last=1;
	for(int i=1;i<=n;++i)
	{
		if(z[i]>0){
			++ans;
			for(int j=last;j<=m;++j)
				if(q[j].st<=i) z[q[j].ed]--;
				else {last=j;break;}
		}
	}
	cout<<ans;
	return 0;
}
