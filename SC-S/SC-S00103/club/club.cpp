#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
struct st{
	int a,b,c,x;
}a[100010];
bool cmp1(st a,st b){
	if(a.x==1 && b.x==1) return (a.a-max(a.b,a.c))<(b.a-max(b.b,b.c));
	if(a.x!=1 && b.x==1) return false;
	return true;
}
bool cmp2(st a,st b){
	if(a.x==2 && b.x==2)return (a.b-max(a.a,a.c))<(b.b-max(b.a,b.c));
	if(a.x!=2 && b.x==2) return false;
	return true;
}
bool cmp3(st a,st b){
	if(a.x==3 && b.x==3)return (a.c-max(a.b,a.a))<(b.c-max(b.b,b.a));
	if(a.x!=3 && b.x==3) return false;
	return true;
}
void solve(){
	long long cnt=0;
	int aa=0,bb=0,cc=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		int mx=max(max(a[i].a,a[i].b),a[i].c);
		cnt+=mx;
		if(a[i].a==mx){
			aa++;
			a[i].x=1;
			continue;
		}
		if(a[i].b==mx){
			bb++;
			a[i].x=2;
			continue;
		}
		if(a[i].c==mx){
			cc++;
			a[i].x=3;
			continue;
		}	
	}
	//cout<<aa<<" "<<bb<<" "<<cc<<endl;
	if(aa>(n/2)){
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=aa-n/2;i++){
			cnt=cnt+max(a[i].b,a[i].c)-a[i].a;
		}
		cout<<cnt<<endl;
		return;
	}
	if(bb>(n/2)){
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=bb-n/2;i++){
			cnt=cnt+max(a[i].a,a[i].c)-a[i].b;
		}
		cout<<cnt<<endl;
		return ;
	}
	if(cc>(n/2)){
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=cc-n/2;i++){		
			cnt=cnt+max(a[i].b,a[i].a)-a[i].c;
		}
		cout<<cnt<<endl;
		return;
	}
	cout<<cnt<<endl;
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 