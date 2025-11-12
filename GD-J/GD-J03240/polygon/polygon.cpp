#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],h[5005],dp[5005],an=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=pow(2,n)-1;i++){
		a[1]++;int o=1,m=0,ma=0;
		for(int j=1,k;j<=n;j++){
			if(a[j]==2)a[j]=0,a[j+1]++;
			else if(a[j]==1)k++;
			if(j==25&&k<3)o=0;
		}if(!o)continue;
		for(int j=1;j<=n;j++){
			if(a[j]==1){
				m+=h[j];
				if(ma<h[j])ma=h[j];
			}
		}if(ma*2<m)an++;
		//for(int j=1;j<=n;j++)cout<<a[j];
		//cout<<endl;
	}cout<<an;
	return 0;
}
