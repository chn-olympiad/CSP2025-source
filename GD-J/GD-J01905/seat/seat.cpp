#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,s,ss;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ss=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==ss){
			ss=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				s++;
				if(s==ss){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				s++;
				if(s==ss){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
