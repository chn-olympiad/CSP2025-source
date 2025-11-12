#include<bits/stdc++.h>
using namespace std;
int t;
struct inf{
	int a,b,c;
}a[100050];
bool cmp(inf b,inf c){
	return b.a>c.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long k=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].a=max(a[i].a,max(a[i].b,a[i].c));
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			k+=a[i].a;
		}
		cout<<k<<endl;
	}
	return 0;
}
