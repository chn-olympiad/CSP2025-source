#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m;
struct f{
	int c,z;
}a[N];
bool cmp(f x,f y){
	return x.c>y.c;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].c;
		a[i].z=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].z==1){
			if((i/n)%2==1){
				if(i%n!=0)cout<<i/n+1<<" "<<n-i%n+1;
				else cout<<i/n<<" "<<n;
			}
			else {
				if(i%n!=0)cout<<i/n+1<<" "<<i%n;
				else cout<<i/n<<" "<<1;
			}
			return 0;
		}
	}
	return 0;
}
