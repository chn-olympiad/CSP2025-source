#include<bits/stdc++.h>
using namespace std;
int c[100005];
struct node{
	int a,b,c,id;
}a[100005];
bool f[100005];
int n;
bool cmp1(node x,node y){
	if(max(x.a,x.b)!=max(y.a,y.b)) return max(x.a,x.b)>max(y.a,y.b);
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.a>y.a;
}
bool check(int i){
	if(a[i].a!=a[i].b) return a[i].a>a[i].b;
	while(a[i].a==a[i].b) i++;
	return a[i].a<a[i].b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		bool f1=1,f2=1;
		for(int i=1;i<=n;i++){
			f[i]=0;
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c!=0) f1=0;
			if(a[i].b!=0) f2=0;
			a[i].id=i;
			a[i].a-=a[i].c;
			a[i].b-=a[i].c;
			ans+=a[i].c;
		}
		if(f1==1){
			if(f2==1){
				sort(a+1,a+n+1,cmp1);
				int sum=0;
				for(int i=1;i<=n/2;i++){
					sum+=a[i].a;
				}
				cout<<sum<<"\n";
			}
			else{
				int sum=0;
				for(int i=1;i<=n;i++){
					sum+=a[i].b;
					a[i].a-=a[i].b;
				}
				sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n/2;i++){
					sum+=a[i].a;
				}
				cout<<sum<<"\n";
			}
			continue;
		} 
		sort(a+1,a+n+1,cmp1);
		int q=0;
		for(int i=1;i<=n;i++){
			if(a[i].a<0&&a[i].b<0){
				q=max(i-1,n/2);
				break;
			}
		}
		if((a[1].a>0||a[1].b>0)&&q==0) q=n;
		for(int i=1;i<=q;i++){
			a[i].a+=a[i].c;
			a[i].b+=a[i].c;
			ans-=a[i].c;
			ans+=a[i].b;
			a[i].a-=a[i].b;
		}
		sort(a+1,a+q+1,cmp2);
		for(int i=1;i<=min(q,n/2);i++){
			if(a[i].a>0) ans+=a[i].a;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2 1
3 2 4
5 3 4
3 5 1
*/
