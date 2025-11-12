#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1005
int n,m;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	int R=a[1];
	int ans=-1;
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<len;i++){
		if(R==a[i]){
			ans=i;
		}
	}
	int row=(ans-1)/n+1;
	if(row%2==0) cout<<row<<" "<<m-(ans-1)%n;
	else cout<<row<<" "<<(ans-1)%n+1;
	fclose(stdout);
	fclose(stdin);
	return 0;
}

