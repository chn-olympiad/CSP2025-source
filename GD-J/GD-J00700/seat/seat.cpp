#include<iostream>
#include<algorithm>
using namespace std;
const int N=15;
int n,m;
int a[N*N],a2[N*N],it;
int t1,t2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i],a2[i]=a[i];
	sort(a2+1,a2+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	if(a2[i]==a[1]) it=i;
	t1=(it-1)/n;
	t2=it-t1*n;
	if((t1+1)%2==0) t2=n-t2+1;
	cout<<t1+1<<" "<<t2;
	return 0;
}
