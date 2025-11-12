#include<bits/stdc++.h>
using namespace std;
int j(int n){
	int sum=1;
	for(int i=1;i<=n;i++){
		sum=sum*i;
		
	}return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=m;i<=n;i++){
		ans=ans+j(n)/j(m);
	}
	cout<<ans%998244353;	

}/*4 4 2 1 4 6 2 3 7 4 2 5 4 3 4 1 1 8 2 4 100 1 3 2 4*/
