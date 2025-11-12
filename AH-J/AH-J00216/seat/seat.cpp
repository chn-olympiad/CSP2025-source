#include <bits/stdc++.h>
using namespace std;

int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int p=a[1];
	sort(a+1,a+1+n*m,cmp);
	int l=1,r=1,rt=1;
	for(int i=1;i<=n*m;i++){
		if (a[i]==p){
			cout<<r<<" "<<l<<endl;
			break;
		}
		l+=rt;
		if (l==0){
			l=1;
			rt=-rt;
			r++;
		}
		if (l==n+1){
			l=n;
			rt=-rt;
			r++;
		}
	}
	return 0;
}
