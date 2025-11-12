#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int bh;
	int z;
}a[105];
int mp[15][15];
bool cmp(node x,node y)
{
	return x.z>y.z;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	bool f=0;
	int sum=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].z;
		a[i].bh=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].bh==1){
			sum=i;
		}
	}
	for(int i=1;i<=m;i++){
		int j;
		if(i%2==0){
			j=n;
			for(;j>=1;j--){
				sum--;
				if(sum==0){
					f=1;
					cout<<i<<" "<<j<<endl;
					break;
				}
			}
		}
		else{
			j=1;
			for(;j<=n;j++){
				sum--;
				if(sum==0){
					f=1;
					cout<<i<<" "<<j<<endl;
					break;
				}
			}
		}
		if(f==1){
			break;
		}
	}
	return 0;
}
