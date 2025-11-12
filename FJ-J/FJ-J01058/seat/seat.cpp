#include <bits/stdc++.h>
using namespace std;

int a[101];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i>1){
			if(a[i]>a[1])
				ans++;
		}
	}
	int c=ans/m+1,r=ans%m;
	if(c%2==0)
		r=m+1-r;
	cout<<c<<' '<<r<<endl;
	return 0;
}
