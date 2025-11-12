#include<bits/stdc++.h>
using namespace std;
#define int long long

int ans=0,n,sum=0;
int a[5010];

void check(int k){
	int q=1,p=1;
	for(int i=k+1;i<=sum;i++)
		q*=i;
	for(int i=1;i<=sum-k;i++)
		p*=i;
	ans=ans+q/p;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			cout<<"CCF is SB,I ak csp-j.";
			return 0;
		}
		if(a[i]==1)
		sum++;
	}
	for(int i=3;i<=sum;i++)
		check(i);
	cout<<ans;
	return 0;
}


//CCF fuck your family
//I AK CSP-J
//CCF your mother died
 
