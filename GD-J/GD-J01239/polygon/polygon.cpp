#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int maxx = -1;
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		cnt+=a[i];
		maxx = max(maxx,a[i]);
	}
	if(cnt - maxx > maxx){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
