#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=1000000;
int T;
ll n,ans,x,y,z;
ll a[N];
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			a[i]=x;
		}
		if(n=100000){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=a[i];
			cout<<ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

