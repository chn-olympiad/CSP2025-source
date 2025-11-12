#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void read(int &x){
	char c=getchar();x=0;
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9') x=x*10+c-48,c=getchar();
}
const int N=1e4+5;
int n,m;
struct NODE{
	int x,id;
	bool operator<(const NODE& z)const {
		return x>z.x;
	}
}a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].x,a[i].id=i;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1)  {
			--i;
			int tmp=i/(n<<1);
			i%=(n<<1),++i;
			if(i<=n) {
				cout<<(tmp<<1)+1<<' '<<i;
			}else{
				cout<<(tmp<<1)+2<<' '<<2*n-i+1;
			}
			break;
		}
	}
	return 0;
}