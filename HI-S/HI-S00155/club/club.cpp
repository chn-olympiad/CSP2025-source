#include<bits/stdc++.h>
using namespace std;
bool cmp(int u,int b)
{
	return u>b;
}
int T;long long n,a[100005][105],js[100005][15],d,sum,su;
int main(){
   freopen("club2.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
    	scanf("%d",&n);
    	d=n/2;
    	sum=0;
    	long long w[7][44];
    	for(int j=1;j<=n;j++)
    	{	
    		scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
    		sum+=max(a[j][1],max(a[j][2],a[j][3]));
    	}
    	cout<<sum<<endl;
    }
	return 0;
}


