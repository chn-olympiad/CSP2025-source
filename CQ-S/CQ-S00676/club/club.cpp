#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,s[4],ans;
struct B{
	int x,id;
};
struct A{
	B a[5];
}a[100005];
bool cmp(B x,B y){
	return x.x>y.x;
}
bool cmp1(A x,A y){
	return x.a[1].x-x.a[2].x>y.a[1].x-y.a[2].x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=s[1]=s[2]=s[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].a[j].x;
				a[i].a[j].id=j;
			}
			sort(a[i].a+1,a[i].a+4,cmp);
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			B x=a[i].a[1],y=a[i].a[2],z=a[i].a[3];
			if(s[x.id]==n/2){
				s[y.id]++;
				ans+=y.x;
			}
			else {
				s[x.id]++;
				ans+=x.x;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
Ô¤¼Æ100
ÏÖÔÚ100 
*/
