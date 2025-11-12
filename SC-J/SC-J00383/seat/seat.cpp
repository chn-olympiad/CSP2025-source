#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m/2;i++){
		swap(a[i],a[n*m-i+1]);
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			b=i;
			break;
		}
	}
	if(((b-1)/n+1)%2==1){
		cout << (b-1)/n+1 << " " << (b-1)%n+1;
	}
	else{
		cout << (b-1)/n+1 << " " << n-(b-1)%n;
	}
	return 0;
}