#include<bits/stdc++.h>
using namespace std;
long long a[105],n,m,rs,cnt,rm,rn;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
    for(int i=1;i<=num;i++)
    {
		cin>>a[i];
	}
	rs=a[1];
	sort(a+1,a+num+1,cmp);
	while(a[cnt]!=rs)cnt++;
	if(cnt%n==0)rm=cnt/n;
	else rm=cnt/n+1;
	if(rm%2==1)
	{
		rn=cnt-(rm-1)*n;
	}
	else{
		rn=n-(cnt-(rm-1)*n)+1;
	}
	cout<<rm<<" "<<rn;
	return 0;
}

