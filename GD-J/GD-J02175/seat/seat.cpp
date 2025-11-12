#include<bits/stdc++.h>
#define F(i,a,b) for(register int i=a;i<=b;i=-~i)
#define D(i,a,b) for(register int i=a;i>=b;i=~-i)
#define ad(k) (k=-~k)
using namespace std;const int N=102;
int n,m,a[N],sum;
int main(){
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	cin>>n>>m;
	F(i,1,n*m){cin>>a[i];if(a[i]>=a[1])sum++;}
	if(sum%n==0){
		cout<<sum/n<<" ";
		if((sum/n)%2==1)cout<<n;
		else cout<<1;
	}else{
		cout<<sum/n+1<<" ";
		if((sum/n+1)%2==1)cout<<sum%n;
		else cout<<n-sum%n+1;
	}
	return 0;
}
