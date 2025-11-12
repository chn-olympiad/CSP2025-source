#include<bits/stdc++.h>
using namespace std;
struct node{
	long long temp=1e9;
};
long long n,m;
long long cnt;
long long a[100010];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long k=n*m;
	for(long long i=0;i<k;i++){
		cin>>cnt;
		a[i]=cnt;
	}
	node g;
	sort(a[0],a[k-1],g.temp); 
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

