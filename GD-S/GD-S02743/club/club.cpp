#include <bits/stdc++.h> 
using namespace std;
const int N=1e5+10;
int T,n,a[N],b[N],c[N];
struct Data{
	int num,id;
	bool operator<(const Data & b) const {
		return num>b.num;
	}
};
void solve(){
	priority_queue<pair<int,int> > q;
	cin>>n;
	int an=0,cn=0,bn=0;
	long long ans=0;
	for(int i=1;i<=n;i++) {
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		Data tmp[3]={(Data){aa,1},(Data){bb,2},(Data){cc,3}};
		sort(tmp,tmp+3);
		int cha=tmp[0].num-tmp[1].num;
		ans+=tmp[0].num*1ll;
		switch(tmp[0].id){
			case 1:
				a[++an]=cha;
				break;
			case 2:
				b[++bn]=cha;
				break;
			case 3:
				c[++cn]=cha;
				break;
		} 
	}
	sort(a+1,a+1+an);
	sort(b+1,b+1+bn);
	sort(c+1,c+1+cn);
	for(int i=an;i>n/2;i--){
		ans-=a[an-i+1];
	}
	for(int i=bn;i>n/2;i--){
		ans-=b[bn-i+1];
	}
	for(int i=cn;i>n/2;i--){
		ans-=c[cn-i+1];
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
