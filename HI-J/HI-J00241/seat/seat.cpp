#include<bits/stdc++.h>
#define ll long long;
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1],ansn=1,ansm=1;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			cout<<ansm<<" "<<ansn;
			return 0;
		}
		if(ansm%2==1){
		if(ansn==n) ansm++;
		else ansn++;	
		}
		else{
		if(ansn==1) ansm++;
		else ansn--;
		}
	}
}


