#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int w=0;
	for(int i=1;i<=n*m;i++){
		w++;
		if(a[i]==r) break;
	}
	int l;
	if(w%n==0)l=w/n;
	else l=w/n+1;
	int x=w-(l-1)*n;
	int h;
	if(l%2==0){
		h=m+1-x;
	}
	else{
		h=x;
	}
	cout<<l<<' '<<h;
	return 0;
} 

