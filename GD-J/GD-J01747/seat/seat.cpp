#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,bj;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++)cin>>a[i];
	b=a[1];
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=l;i++)if(a[i]==b)bj=i;
	//cout<<bj<<endl;
	if(((bj-1)/n)%2==0)cout<<(bj-1)/n+1<<" "<<(bj-1)%n+1;
	else cout<<(bj-1)/n+1<<" "<<n+1-((bj-1)%n+1);
	return 0;
} 
