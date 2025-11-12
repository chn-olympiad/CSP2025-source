#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005;
int n,m;
struct Node{
	int id,val;
}a[N];
bool cmp(Node x,Node y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			int ans1=0;
			if(i%n==0){
				cout<<i/n<<' ';
				ans1=i/n;
			}
			else {
				ans1=i/n+1;
				cout<<i/n+1<<' ';
			}
			int mm=i%n;
			if(ans1%2==1){
				if(mm==0) cout<<n;
				else cout<<mm;
			}
			else{
				if(mm==0) cout<<1;
				else cout<<n-mm+1;
			}
			break;
		}
	}
	return 0;
}