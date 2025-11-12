#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=120;
int n,m,len;
int S,a[maxn];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;len=n*m;
	for(int i=1;i<=len;i++){cin>>a[i];}S=a[1];
	sort(a+1,a+1+len,greater<int>());
	for(int t=1,i=1,j=1;t<=len;t++){
		if(a[t]==S){cout<<i<<' '<<j<<'\n';break;}
		if(i&1){
			if(j==n) i++;
			else j++;
		}
		else{
			if(j==1) i++;
			else j--;
		}
	}
	return 0;
}

