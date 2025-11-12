#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i = 1; i <= n*m; i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int po;
	for(int i = 1; i <= n*m; i++){
		if(a[i]==r){
			po=i;
			break;
		}
	}
	int lie=po/n;
	po%=n;
	if(po!=0){
		lie++;
	}
	int hang;
	if(lie%2==1){
		hang=po;
		if(hang==0) hang=n;
	}
	else{
		hang=n-po+1;
	}
	cout<<lie<<' '<<hang;
	return 0;
}