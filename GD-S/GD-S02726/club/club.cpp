#include<bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define int long long
using namespace std;
const int N=1e5+30;
int n;
struct node{
	int a,b,c;
}a[N];
void slove(){
	cin>>n;
	int m1=0,m2=0,m3=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		if(max({a[i].a,a[i].b,a[i].c})==a[i].a)m1++;
		if(max({a[i].a,a[i].b,a[i].c})==a[i].b)m2++;
		if(max({a[i].a,a[i].b,a[i].c})==a[i].c)m3++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=max({a[i].a,a[i].b,a[i].c});
	}
	int ks[N]={},cnt=0;
	if(m1<=n/2 && m2<=n/2 && m3<=n/2){
		cout<<ans<<endl;
		return ;
	}
	else{
		if(m1>n/2){
			for(int i=1;i<=n;i++){
				if(max({a[i].a,a[i].b,a[i].c})==a[i].a){
					ks[++cnt]=min(a[i].a-a[i].b,a[i].a-a[i].c);
				}
			}
			sort(ks+1,ks+1+cnt);
			for(int i=1;i<=m1-n/2;i++){
				ans-=ks[i];
			}
		} else if(m2>n/2) {
			for(int i=1;i<=n;i++){
				if(max({a[i].a,a[i].b,a[i].c})==a[i].b){
					ks[++cnt]=min(a[i].b-a[i].a,a[i].b-a[i].c);
				}
			}
			sort(ks+1,ks+1+cnt);
			for(int i=1;i<=m2-n/2;i++){
				ans-=ks[i];
			}
		} else {
			for(int i=1;i<=n;i++){
				if(max({a[i].a,a[i].b,a[i].c})==a[i].c){
					ks[++cnt]=min(a[i].c-a[i].b,a[i].c-a[i].a);
				}
			}
			sort(ks+1,ks+1+cnt);
			for(int i=1;i<=m3-n/2;i++){
				ans-=ks[i];
			}
		}
	}
	cout<<ans<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	file(club); 
	int T;
	cin>>T;
	while(T--){
		slove();//看在我都写了slove的面上给我上迷惑行为大赏吧qwq，顺便把我J03008T2也看一下，我J挂完了，能满足我这个愿望吗 
	}
	return 0;
}

