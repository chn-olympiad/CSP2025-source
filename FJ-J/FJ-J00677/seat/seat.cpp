#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	if(x>y)return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,a[110],ans;
	cin>>n>>m>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			ans=i;
			break;
		}
	}
	cout<<ceil(float(ans)/float(m*1.0))<<" ";
	if(int(ceil(float(ans)/float(m*1.0)))%2==1)cout<<ans-n*(int(ceil(float(ans)/float(m*1.0)))-1);
	else cout<<n*ceil(float(ans)/float(m*1.0))-ans+1;
	return 0;
}
