#include<bits/stdc++.h>
#define int long long
using namespace std;
struct member{
	int a;
	int b;
	int c;
	int cha; 
}ren[100005];
int t; 
int n,num[4],ans;
int midit(int a,int b,int c){
	if(a>=b&&b>=c) return b;
	if(a>=c&&c>=b) return c;
	if(b>=a&&a>=c) return a;
	if(b>=c&&c>=a) return c;
	if(c>=a&&a>=b) return a;
	if(c>=b&&b>=a) return b;
}
int maxit(int a,int b,int c){
	if(a>=b&&b>=c) {num[1]++;return 1;}
	if(a>=c&&c>=b) {num[1]++;return 1;}
	if(b>=a&&a>=b) {num[2]++;return 2;}
	if(b>=c&&c>=a) {num[2]++;return 2;}
	if(c>=a&&a>=b) {num[3]++;return 3;}
	if(c>=b&&b>=a) {num[3]++;return 3;}
	
}
bool cmp(member a,member b){
	return a.cha<b.cha;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(num,0,sizeof(num));
	ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ren[i].a>>ren[i].b>>ren[i].c;
			ren[i].cha=max(max(ren[i].a,ren[i].b),ren[i].c)-midit(ren[i].a,ren[i].b,ren[i].c);
		}
		sort(ren+1,ren+n+1,cmp);
	for(int i=n;i>=1;i--){
		if(num[maxit(ren[i].a,ren[i].b,ren[i].c)]<=n/2) ans+=max(max(ren[i].a,ren[i].b),ren[i].c);
		else ans+=midit(ren[i].a,ren[i].b,ren[i].c);
	}cout<<ans<<endl;
	}
	return 0;
}
