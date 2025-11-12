#include<bits/stdc++.h>
using namespace std;
const int N=1E5+5;
int a[N];
int t,n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			int l,v,r;
			cin>>l>>r>>v;
			a[i]=l;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}	

