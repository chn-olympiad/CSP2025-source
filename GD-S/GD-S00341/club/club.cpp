#include<bits/stdc++.h>
using namespace std;
int t,n,b[100001];
struct node{
	int a,b,c;
}a[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			ans+=a[i].a;
			b[i]=a[i].a-a[i].b;
		}
		stable_sort(b+1,b+n+1);
		for(int i=1;i<=n/2;i++){
			ans-=b[i];
		}
		cout<<ans<<endl;
	}
}
