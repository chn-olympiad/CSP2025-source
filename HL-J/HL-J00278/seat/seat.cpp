#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[150],sum=0,cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	a[0]=k;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		sum++;
	}
	for(int i=0;i<n*m-1;i++){
		for(int j=0;j<n*m-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]>=k) cnt++;
	}
	long long c=0;
	if(cnt<=n){
		c=1;
		cout<<1<<" ";
	}else{
		if(cnt%n==0){
			c=cnt/n;
			cout<<cnt/n<<" ";
		}else if(cnt%n!=0){
			c=cnt/n+1;
			cout<<c<<" ";
		}
	}
	if(c%2==1){
		if(cnt%n==0){
			cout<<n;
		}else if(cnt%n!=0){
			cout<<cnt%n;
		}
	}else if(c%2==0){
		if(cnt%n==1){
			cout<<n;
		}if(cnt%n==0){
			cout<<1;
		}if(cnt%n!=0&&cnt%n!=1){
			cout<<n-cnt%n+1;
		}
	}
	return 0;
}
