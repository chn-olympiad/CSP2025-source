#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int n,m,R,Ri = 1,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&R);
	a[0] = R;
	for(int i = 1;i<n*m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>R) Ri++;
	}
	sort(a,a+n*m,cmp);
	int l = 1;
	while(l<=m)
	{
		if(Ri<=l*n)
		{
			int t = 1;
			while(t<=n)
			{
				if((l-1)*n+t == Ri)
				{
					if(l%2 == 1) printf("%d %d",l,t);
					else printf("%d %d",l,n-t+1);
					return 0;
				}
				else t++;
			}
		}
		else l++;
	}
	return 0;
}
