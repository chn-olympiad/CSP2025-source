#include<bits/stdc++.h>
using namespace std;
struct cy{
	int a,b,c;
};
cy a[100005],d[100005];
cy modd;
int t,n;
void cleaner(){
	for(int i=0;i<100005;i++){
		a[i]=modd;
		d[i]=modd;
	}
	return;
}
bool cmp(cy x,cy y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		bool flag=true;
		cleaner();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0){
				flag=false;
			}
		}
		if(flag){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}//rp++