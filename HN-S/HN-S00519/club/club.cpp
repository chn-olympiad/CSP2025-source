#include<bits/stdc++.h>
using namespace std;
int tot,n,a[100010][3],s[100010],b0,b1,b2,c,now;
void asd(int k)
{
	if (k>n)
	{
		if (now>tot);
		    tot=now;
		return;
	}
	if (b0+1<=c&&now+a[k][0]+s[n]-s[k]>=tot)
	{
		now+=a[k][0];
		b0++;
		asd(k+1);
		now-=a[k][0];
		b0--;
	}
	if (b1+1<=c&&now+a[k][1]+s[n]-s[k]>=tot)
	{
		now+=a[k][1];
		b1++;
		asd(k+1);
		now-=a[k][1];
		b1--;
	}
	if (b2+1<=c&&now+a[k][2]+s[n]-s[k]>=tot)
	{
		now+=a[k][2];
		b2++;
		asd(k+1);
		now-=a[k][2];
		b2--;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (;t>0;t--)
	{
		tot=b0=b1=b2=now=0;
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		c=n/2;
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int n;
			n=max(a[i][0],a[i][1]);
			n=max(n,a[i][2]);
			s[i]=s[i-1]+n;
		}
    	asd(1);
	    cout<<tot<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
