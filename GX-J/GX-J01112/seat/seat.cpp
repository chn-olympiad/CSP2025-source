#include <bits/stdc++.h>
using namespace std;
int x=0,y=0,a[110];int d=0,s=0;
int main(){   
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	s=x*y;
	for(int i=1;i<=x*y;i++)cin>>a[i];
	d=a[1];
	sort(a+1,a+x*y+1);
	for(int j=1;j<=y;j++){
		if(j%2==1)for(int i=1;i<=x;i++){
			if(a[s]!=d)s--;
			else {cout<<j<<" "<<i;
				return 0;}
			}else for(int i=x;i>=1;i--){
			if(a[s]!=d)s--;
			else {cout<<j<<" "<<i;
				return 0;}
	}}
	return 0;
}

