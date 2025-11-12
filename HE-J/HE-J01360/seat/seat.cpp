#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int T;
	T=1;
	while(T--){
	int n,m,sum=0; 
	scanf("%d %d",&n,&m);
	int a[n*m+5];
	for(long i=0;i<n*m;i++){
		scanf("%d",&a[i]);
	}
	int r=a[0];
	sort(a,a+n*m);
	for(long i=n*m-1;i>=0;i--){
		sum++;
		if(a[i]==r)break;
	}
	if(n==1){
		cout<<sum<<' '<<1;
		return 0;
	}
	if(m==1){
		cout<<1<<' '<<sum;
		return 0;
	}
	int x=sum/n;
	if(sum%n!=0){
		if(x%2==1){
		cout<<x+1<<' '<<n-(sum%n)+1;
		}
		else cout<<x+1<<' '<<sum%n;
	}else{
		if(x%2==1){
		cout<<x<<' '<<n;
		}
		else cout<<x<<' '<<1;
	} 
	}
}

