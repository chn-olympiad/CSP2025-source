#include<bits/stdc++.h>
using namespace std;
long long k[2000];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>k[i];
	}long long z=k[1];
	sort(k+1,k+n*m+1);

	long long x=lower_bound(k+1,k+n*m+1,z)-k;
	x=n*m-x+1;
	long long h=0;
	while(x>n){
		x-=n;
		h++;
	}cout<<h+1<<" ";

	if(h%2==0){
		cout<<x;
	}else{
		cout<<n-x+1;
	}cout<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

