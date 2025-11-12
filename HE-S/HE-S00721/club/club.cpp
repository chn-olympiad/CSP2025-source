#include <bits/stdc++.h>
using namespace std;
int n,t,a[100005],b[100005],c[100005],sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			sum+=max(a[i],max(b[i],c[i]));
		}
		cout<<sum<<endl;
	}
	return 0;
}

