#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,a[N],s,c,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			s=i;
			break;
		}
	}
	s=n*m-s+1;
	c=s/n;
	d=s%n;
	if(d!=0) c++;
	if(d==0) d=n;
	if(c%2==0)
		d=n-d+1;
	cout<<c<<" "<<d;
}
