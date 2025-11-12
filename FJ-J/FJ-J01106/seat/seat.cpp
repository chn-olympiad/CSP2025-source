#include<bits/stdc++.h> 
using namespace std;
long long n,m,cj[105],first,tmp,flag;

bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>cj[i];

	first=cj[1];
	sort(cj+1,cj+1+n*m,cmp);
	long long l=1,r=n*m,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(cj[mid]==first)
		{
			tmp=mid;
			break;
		}
		else if(cj[mid]>first) l=mid+1;
		else r=mid-1;
	}
	
	flag=tmp/n;
	if(flag*n==tmp)
	{
		if(flag%2==0) cout<<flag<<" "<<1;
		else cout<<flag<<" "<<n;
	}
	else
	{
		cout<<flag+1<<" ";
		if((flag+1)%2==0) cout<<n+1-(tmp%n);
		else cout<<tmp%n;
	}
	return 0;
}
