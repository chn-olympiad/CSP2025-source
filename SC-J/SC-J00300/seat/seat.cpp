#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,a[1000];
int mp[11][11];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1],ri=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			ri=i;
			break;
		}
	}
//	cout<<ri<<" ";
	int l=(ri+n-1)/n;
	cout<<l<<" ";
	if(l%2==0)cout<<n-(ri%n)+1;
	else cout<<(ri+n-1)%n+1;
	return 0;
}


