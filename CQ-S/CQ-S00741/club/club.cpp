#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,a[N],b[N],c[N],ans,yi[N],er[N],sa[N];//2-1 3-2 3-1 
/*
孩子，这好像不太对
由于只可能有一个俱乐部超出 n/2
我们需要降低超出部分的最小额度
这个随便放都没有问题，最小化差值就ok 
不是bro你怎么15:00才过 
*/
void solve(){
	cin>>n;ans=0;//初始化 yi er sa！！！ 
	int x=0,y=0,z=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i]; 
		int ma=max(a[i],max(b[i],c[i]));
		ans+=ma;
		if(ma==a[i]) x++,yi[x]=min(a[i]-b[i],a[i]-c[i]);
		else if(ma==b[i]) y++,er[y]=min(b[i]-a[i],b[i]-c[i]);
		else z++,sa[z]=min(c[i]-a[i],c[i]-b[i]);
	}
	sort(yi+1,yi+1+x);
	sort(er+1,er+1+y);
	sort(sa+1,sa+1+z);
	if(x>n/2){
		for(int i=1;i<=x-n/2;i++) ans-=yi[i];
	}
	if(y>n/2){
		for(int i=1;i<=y-n/2;i++) ans-=er[i];
	}
	if(z>n/2){
		for(int i=1;i<=z-n/2;i++) ans-=sa[i];
	}
	cout<<ans<<endl;
}
int main(){
	
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
}
