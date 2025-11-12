#include <bits/stdc++.h>
using namespace std;
int n,m,s[1005],nx,ny;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>s[i];
	}
	int r=s[1],sum=0;
	for(int i=1;i<=num;i++){
		if(s[i]>r) sum++;
	}
	nx=1+sum/m;
	if(nx%2==0){
		ny=m-sum%m;
	}
	else ny=1+sum%m;
	cout<<nx<<" "<<ny;
	return 0;
}
