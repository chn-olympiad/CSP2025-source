#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=105;
int n,m;
int a[MAXN];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1,sum=1;
	while(1){
		if(cnt==a[sum]){
			cout<<j<<' '<<i;
			return 0;
		}
		if(i==n&&j%2==1){
			j++;
		}else if(i==1&&j%2==0){
			j++;
		}else if(j%2==1){
			i++;
		}else if(j%2==0){
			i--;
		}
		sum++;
	}
	return 0;
} 
