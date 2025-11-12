#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,f,ans1=1,ans2=1;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cout<<ans1<<" "<<ans2<<'\n';
			return 0;
		}
		if(f) ans2--;
		else ans2++;
		if(ans2>n) ans1++,ans2=n,f^=1;
		if(ans2<1) ans1++,ans2=1,f^=1;
	}
	return 0;
}