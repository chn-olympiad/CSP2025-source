#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
int n,m;
int a[505];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt;
	for(int i=1;i<=n*m;i++)
		if(a[i]==tmp) cnt=i;
	if(cnt%n==0){
		if(cnt/n%2==1) cout<<cnt/n<<" "<<n;
		else cout<<cnt/n<<" "<<1;
	}
	else{
		if((cnt/n+1)%2==1) cout<<cnt/n+1<<" "<<cnt%n;
		else cout<<cnt/n+1<<" "<<n-cnt%n+1;
	}
	return 0;
}
