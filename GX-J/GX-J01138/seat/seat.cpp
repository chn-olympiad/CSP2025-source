#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;int a[n*m+3];
for(int i=0;i<n*m;i++){
	cin>>a[i];
}int w=a[0];
sort(a,a+n*m);
int l=0,r=n*m-1;
while(l<r){
	int mid=(l+r)/2;
	if(a[mid]>=w){
		r=mid;
		}
	else l=mid+1;
}
	if(((((m*n-l)/n)%2)==0)&&(((m*n-l)%n)==0)){
	cout<<(m*n-l)/n<<" "<<1;return 0;}
	if(((((m*n-l)/n)%2)!=0)&&(((m*n-l)%n)==0)){
		cout<<(m*n-l)/n<<" "<<n;return 0;
	}



	if((((m*n-l)/n+1)%2)==0&&((m*n-l)%n!=0)){
	cout<<(m*n-l)/n+1<<" "<<n-(m*n-l)%n+1;return 0;}
	if((((m*n-l)/n+1)%2!=0)&&((m*n-l)%n!=0)){
		cout<<(m*n-l)/n+1<<" "<<(m*n-l)%n;return 0;

}


return 0;
}
