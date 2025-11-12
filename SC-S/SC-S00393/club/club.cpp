#include <bits/stdc++.h>
using namespace std;
struct nd{
	int a,b,c;
}a[200005];
int n,t,ans;
bool f1=1,f2=1,f3=1;
bool cmp(nd a,nd b){
	return a.a>b.a;
}
bool cmp2(nd a,nd b){
	return a.c>b.c;
}
bool cmp3(nd a,nd b){
	return a.b>b.b;
}
bool cdp(nd a,nd b){
	return (a.b-a.c)>(b.b-b.c);
}
bool cdp2(nd a,nd b){
	return (a.a-a.c)>(b.a-b.c);
}
bool cdp3(nd a,nd b){
	return (a.a-a.b)>(b.a-b.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a!=0) f1=0;
			if(a[i].b!=0) f2=0;
			if(a[i].c!=0) f3=0;
		}
		if(f1 && f2 && f3){
			ans=0;
		}
		else if(f3 && f2){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
		}
		else if(f1 && f2){
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].c;
			}
		}
		else if(f1 && f3){
			sort(a+1,a+1+n,cmp3);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].b;
			}
		}
		else if(f1){
			sort(a+1,a+1+n,cdp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].b;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i].c;
			}
		}
		else if(f2){
			sort(a+1,a+1+n,cdp2);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i].c;
			}
		}
		else if(f3){
			sort(a+1,a+1+n,cdp3);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i].b;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}