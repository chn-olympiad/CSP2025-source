#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[900],t,a1,a2=1;
bool cmp(int s1,int s2){
	return s1>s2;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out"," w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			cout<<(i+n-1)/n<<' ';
			if(((i+n-1)/n)%2){
				ll x=i%n;
				if(x==0) cout<<m;
				else cout<<x;
			}
			else cout<<m-i%n+1;
		}
	}
	return 0;
} 
