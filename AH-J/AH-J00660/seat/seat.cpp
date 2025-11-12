#include<bits/stdc++.h>
using namespace std;
#define N 105
int n,k,x,f,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n*k;i++)
		cin>>a[i];
	x=a[0];
	sort(a,a+n*k);
	for(int i=0;i<n*k;i++)
		if(a[i]==x){
			f=n*k-i;
			break;
		}
	cout<<(f+n-1)/n<<" "<<min(f%(n*2),n*2-f%(n*2));
	return 0;
}
