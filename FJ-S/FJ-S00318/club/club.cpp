#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define endl '\n'
#define xx a[i].x
#define yy a[i].y
#define zz a[i].z
const int N = 1e5+5;
const int base = 1e9+7;
const int mod = 998244353;
struct node{
	int x,y,z;
}a[N];
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){ x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
void write(ll x){
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,T;
int cnt1,cnt2,cnt3,ans;
int dis[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T = read();
	while(T--){
		n = read();
		cnt1=cnt2=cnt3=ans=0;
		for(int i = 1 ; i <= n ; i ++){
			a[i].x = read();
			a[i].y = read();
			a[i].z = read();
			ans += max(a[i].x,max(a[i].y,a[i].z));
			if(xx>=yy&&xx>=zz) cnt1++;
			else if(yy>=xx&&yy>=zz) cnt2++;
			else if(zz>=xx&&zz>=yy) cnt3++;
		}
		if((cnt1<=n/2)&&(cnt2<=n/2)&&(cnt3<=n/2)){
			cout << ans << endl;
//			cout << "awa\n";
			continue;
		}
		if(cnt2>n/2){
			swap(cnt1,cnt2);
			for(int i = 1 ; i <= n ; i ++) swap(a[i].x,a[i].y);
		}
		if(cnt3>n/2){
			swap(cnt1,cnt3);
			for(int i = 1 ; i <= n ; i ++) swap(a[i].x,a[i].z);
		}
//		for(int i = 1; i <= n ; i ++){
//			printf("%d %d %d\n",xx,yy,zz);
//		}
//		cout << "Mewo ";
//		cout << cnt1 << endl;
		for(int i = 1 ; i <= n ; i ++){
			int res = min(a[i].x-a[i].y,a[i].x-a[i].z);
			dis[i]=(res>=0?res:0x3f3f3f3f);
//			cout << dis[i] << ' ';
		}
//		cout << endl;
		sort(dis+1,dis+1+n);
//		for(int i = 1 ; i <= n ; i ++){
//			dis[i]=min(a[i].x-a[i].y,a[i].x-a[i].z);
//			cout << dis[i] << ' ';
//		}
//		cout << endl;
		for(int i = 1 ; i <= cnt1-(n/2) ; i ++){
			ans -= dis[i];
		}
		cout << ans << endl;
	}
	return 0;
}

