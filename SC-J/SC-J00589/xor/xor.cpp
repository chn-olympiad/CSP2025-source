#include<bits/stdc++.h>
using namespace std;
long long flag,ktv,n,fw[500500][3],a[505000],qzh[501000],x,y,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>ktv;
	for(int i=1;i<=n;i++) cin>>a[i],qzh[i]=(qzh[i-1]^a[i]);
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			flag=0;
			x=(i+j-1),y=(i*2+j-1);
			
			if((qzh[y]^qzh[x-1])==ktv&&x<=n&&y<=n)
			{
				ans++;
				for(int k=1;k<=ans;k++)
				{
					if(x>=fw[k][1]&&x<=fw[k][2])
					{
						ans--;
						flag=1;
						j=max(j,int(fw[k][2]+1-2*i)-1);
						break;
					}
					if(y>=fw[k][1]&&fw[k][2]>=y)
					{
						ans--;
						flag=1;
						j=max(j,int(fw[k][2]+1-2*i)-1);
						break;
					}
					if(y>=fw[k][2]&&fw[k][1]>=x)
					{
						ans--;
						flag=1;
						j=max(j,int(fw[k][2]+1-2*i)-1);
						break;
					}
				}
				if(!flag) fw[ans][1]=x,fw[ans][2]=y;
//				if(!flag) cout<<x<<" "<<y<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}