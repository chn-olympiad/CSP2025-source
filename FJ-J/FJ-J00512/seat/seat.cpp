#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 105
int n,m;
int p;
int a[N];
int l,r;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	l=1,r=n*m;
	while(1){
		int mid=(l+r)/2;
		if(a[mid]==p){
			l=mid;
			break;
		}
		else if(a[mid]>p){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	if((l/n)%2==0&&l%n==0){
		cout<<l/n<<" 1";
	}
	else if((l/n)%2==1&&l%n==0){
		cout<<l/n<<" "<<n;
	}
	else if((l/n)%2==0){
		cout<<l/n+1<<" "<<l%n;
	}
	else if((l/n)%2==1){
		cout<<l/n+1<<" "<<n-(l%n)+1;
	}
	return 0;
}
