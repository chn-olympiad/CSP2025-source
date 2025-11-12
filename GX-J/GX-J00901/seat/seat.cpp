#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],q,w,e,c;
	cin>>n>>m;
	q=n*m;
	for(int i=1;i<=q;i++){
		cin>>a[i];
		if(i==1){
			w=a[i];
		}
    }
    sort(a+1,a+q+1);
    for(int o=q;o>=1;o--){
		if(a[o]==w){
			e=q-o+1;
			break;
	    }
	}
	c=e/n;
	if(e%n==0&&c%2==1) cout<<c<<" "<<n;
	if(e%n==0&&c%2==0) cout<<c<<" "<<"1";
	if(e%n!=0&&c%2==0) cout<<c+1<<" "<<e%n;
	if(e%n!=0&&c%2==1) cout<<c+1<<" "<<n+1-e%n;
	return 0;
}
