#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int xx,int yy)
{
	return xx>yy;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;int ct=n*m;
	for(int i=1;i<=ct;i++)
	{
		cin>>a[i];
	}
	int wz=a[1],id;
	sort(a+1,a+ct+1,cmp);
	for(int i=1;i<=ct;i++){
		if(a[i]==wz){
			id=i;
			break;
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		if(i&1){
			for(int j=1;j<=n;j++){
				sum++;
				if(sum==id)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				sum++;
				if(sum==id)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 