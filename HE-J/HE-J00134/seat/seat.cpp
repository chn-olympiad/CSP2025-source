#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=110;
int n,m,a[N],sum,cnt,b[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+k+1);
	int j=1;
	for(int i=k;i>=1;i--){
		b[j]=a[i];
		j++;
	}
	for(int i=1;i<=k;i++){
		if(sum==b[i]){
			cnt=i;
			break;
		}
	}
	if(cnt%n==0){
		cout<<cnt/n<<" ";
	}
	else{
		cout<<cnt/n+1<<" ";
	}
	int p=cnt%(2*n);
	if(p>n){
		int y=p%n;
		cout<<n-y+1;
	}
	else{
		cout<<p;
	}
	return 0;
}
