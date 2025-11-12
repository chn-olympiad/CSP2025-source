#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])
		 cnt++;
	}
	int i=1,j=1;
	while(cnt--)
	{
		if(i==n&&j%2==1){
			j++;
			continue;
		}
		if(i==1&&j%2==0){
			j++;
			continue;
		}
		if(j%2==1)
		 i++;
		else
		 i--;
	}
	cout<<j<<" "<<i;
	return 0;
}
