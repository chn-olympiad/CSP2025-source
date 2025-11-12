#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
struct A{
	int a,b,c;
}a[100005];
A sta1[100005],sta2[100005],sta3[100005];
int p1=1,p2=1,p3=1;
ll ans;
bool cmp1(A B,A C){
	return min(abs(B.a-B.c),abs(B.a-B.b))<min(abs(C.a-C.c),abs(C.a-C.b));
}
bool cmp2(A B,A C){
	return min(abs(B.b-B.c),abs(B.b-B.a))<min(abs(C.b-C.c),abs(C.b-C.a));
}
bool cmp3(A B,A C){
	return min(abs(B.c-B.a),abs(B.c-B.b))<min(abs(C.c-C.a),abs(C.c-C.b));
}
int main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		p1=p2=p3=1;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			ans+=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				sta1[p1++]=a[i];
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				sta2[p2++]=a[i];
			}
			else{
				sta3[p3++]=a[i];
			}
		}
		if(p1>n/2+1||p2>n/2+1||p3>n/2+1){
			if(p1>n/2+1){
				sort(sta1+1,sta1+p1,cmp1);
				for(int i=1;i<p1-n/2;i++){
					ans-=sta1[i].a-max(sta1[i].b,sta1[i].c);
				}
			}
			else if(p2>n/2+1){
				sort(sta2+1,sta2+p2,cmp2);
				for(int i=1;i<p2-n/2;i++){
					ans-=sta2[i].b-max(sta2[i].a,sta2[i].c);
				}
			}
			else{
				sort(sta3+1,sta3+p3,cmp3);
				for(int i=1;i<p3-n/2;i++){
					ans-=sta3[i].c-max(sta3[i].b,sta3[i].a);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
