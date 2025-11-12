#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++){
		cin >> a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	if(a[1]==r)cout<<1<<" "<<1;
	else if(a[n*m]==r)cout<<m<<" "<<n;
	else{
		for(int i=2;i<n*m;i++){
			int s;
			if(i%m==0)s=i/m;
			else s=i/m+1;
			if(a[i]==r){
				cout<<s;
				if(s%2==1)cout<<" "<<(i-1)%m+1;
				else cout<<" "<<n-i%m+1;
				break;
			}
		}
	}
	return 0;
}
