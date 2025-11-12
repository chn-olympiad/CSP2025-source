#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+5;
long long a[N];
long long b[N];
long long c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
    cin>>t;
    for(int i=1;i<=t;i++){
    	int n;
    	cin>>n;
    	for(int j=1;j<=n;j++){
	       cin>>a[j]>>b[j]>>c[j];
	   }
	}
	for(int i=1;i<=t;i++){
		cout<<max({a[1]+b[2],a[1]+c[2],b[1]+c[2],b[1]+a[2],c[1]+a[2],c[1]+b[2]})<<endl;
	}
	return 0;
}
