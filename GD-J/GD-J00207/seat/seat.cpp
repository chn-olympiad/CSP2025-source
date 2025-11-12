#include<bits/stdc++.h>
using namespace std;
int n,m,a[225],ans,cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n*m;i++) cin>>a[i];
	ans = a[0];
	sort(a,a+n*m,cmp);
	for(int i = 0;i<n*m;i++){
		if(a[i] == ans){
			cnt = i;
			break;
		}
	}
	cout<<cnt/n+1<<' ';
	if(cnt/n%2 == 1) cout<<n-cnt%n<<'\n';
	else cout<<cnt%n+1<<'\n';
	return 0;
} 
