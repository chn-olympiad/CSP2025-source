#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
while(t>0){
	int n,q=0,w=0,e=0,max=0;
	cin>>n;
	int b[n+1][4],z[n+1],x[n+1],y[n+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
			if(b[i][1]>=b[i][2]&&b[i][1]>=b[i][3])
			{
				if(q>n/2)break;
				q++;
				z[i]=b[i][1];
				max=max+z[i];
				
			}
			if(b[i][1]<=b[i][2]&&b[i][2]>=b[i][3])
			{
			if(w>n/2)break;
				w++;
				x[i]=b[i][2];
				max=max+x[i];
			}
			if(b[i][3]>=b[i][2]&&b[i][1]<=b[i][3])
			{
				if(e>n/2)break;
				e++;
				y[i]=b[i][3];
				max=max+y[i];
			}
	}
	cout<<max<<endl;
	t--;
}
	return 0;
	
}
