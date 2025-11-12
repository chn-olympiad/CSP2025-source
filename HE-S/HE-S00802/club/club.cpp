#include<bits/stdc++.h>
using namespace std;
struct S{
	int a,b,c;
}a[100010];
long long n,f,f2,ans,ans2;
bool cmp(S x,S y){
	return x.a>y.a;
}
bool cmp2(S x,S y){
	return x.b>y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b==0&&a[i].c==0) f=1;
			else if(a[i].b&&a[i].c==0) f2=1;
		}
		if(f2){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i].b;
			}
			ans2=ans,ans=0;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].b;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i].a;
			}
			cout<<max(ans,ans2)<<endl;
		}else{
			if(f){
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].a;
				}
				cout<<endl;
			}
		}
	}
 return 0;
}
