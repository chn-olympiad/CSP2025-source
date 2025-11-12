#include<iostream>
#include<algorithm>
using namespace std;
int a[102];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=t;i++)cin>>a[i];
    int sr=a[1];
    sort(a+1,a+t+1);
    int pos=t-(lower_bound(a+1,a+t+1,sr)-a)+1;
    int c=(pos-1)/n+1;
    int r=(c&1?(pos-1)%n+1:n-(pos-1)%n);
    cout<<c<<' '<<r;
	return 0;
}
