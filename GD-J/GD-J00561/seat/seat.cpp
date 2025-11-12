#include<bits/stdc++.h>
using namespace std;
float n,m,pm=1;
int re,ks;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>re;
	for(int i=1;i<n*m;i++){
		cin>>ks;
		if(ks>re)
			pm++;
	}
	int c=ceil(pm/n);
	int r=(c%2==0?(n+1)-pm+(c-1)*n:pm-(c-1)*n);
	cout<<c<<" "<<r;
	return 0;
}
