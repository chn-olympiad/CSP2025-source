#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,a[N],a1,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[++cnt];
	}
	a1=a[1];
	sort(a+1,a+cnt+1);
	reverse(a+1,a+cnt+1);
	cnt=0;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(a[++cnt]==a1){
				cout<<j<<" "<<i;
				return 0;
			}
		}
		j++;
		if(j>m)break;
		for(int i=n;i>=1;i--){
			if(a[++cnt]==a1){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
