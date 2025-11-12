#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
struct oo{
	int l,r;
	bool g=1;
};
oo b[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int t=1;int ans=0;int sum=0;int s=1; 
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];if(a[i]!=1) s=0;
	}
	if(s==1){
		n/=2;
		cout<<n;return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k){
			b[t].l=i;b[t].r=i;sum++;
			t++;continue;
		}
		int j=i+1;
		ans=a[i];
		do{
			ans^=a[j];
			if(ans==k){
			b[t].l=i;b[t].r=j;
			t++;sum++;break;
			}
			j++;
		}while(j<=n+1);
	}
	//cout<<sum<<endl;
	int baohan=0;
	for(int i=1;i<t;i++)
	{
		for(int j=i+1;j<t;j++)
		{
			if(((b[i].l<=b[j].l&&b[i].r>=b[j].l)||(b[i].l<=b[j].r&&b[i].r>=b[j].r))&&b[i].g&&b[j].g){
				baohan++;b[j].g=0;
			} 
		}
		if(baohan<=1) sum-=baohan;
		else sum-=1;
	//	cout<<baohan<<endl;
		baohan=0;
	}
	cout<<sum;
	return 0;
}
