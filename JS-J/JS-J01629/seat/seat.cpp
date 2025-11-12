#include "bits/stdc++.h"
using namespace std;
int n,m;
int a[1000];
int ans;

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,sum=1,cnt=1;
	while(1){
		//cout<<sum<<" "<<x<<" "<<y<<" "<<cnt<<endl;
		if(y==m+1){
			break;
			}
		if(a[sum]==ans){
			cout<<y<<" "<<x<<endl;
			break;
		}
		if(x==n&&(cnt==1)){
			y++;
			cnt=-cnt;
		}else if((x==1)&&(y!=1)&&(cnt==-1)){
			cnt=-cnt;
			y++;
		}else{
			x+=cnt;
		}sum++;
	}
    return 0;
}
