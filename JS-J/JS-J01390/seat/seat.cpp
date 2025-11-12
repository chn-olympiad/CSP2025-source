#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			if(i<=n){
				cout<<1<<' '<<i;
				break;
			} 
			else{
				int t=i/n;
				if(t%2==1){
					if(t+1<=m){
						if(i%n==0){
							cout<<t+1<<' '<<1;
						}else cout<<t+1<<' '<<n-i%n+1;
					} 
					else{
						if(i%n==0){
							cout<<m<<' '<<1;
						}else cout<<m<<' '<<n-i%n+1;
					}
					break;
				}else{
					if(t+1<=m){
						if(i%n==0){
							cout<<t+1<<' '<<i%n;
						}else cout<<t+1<<' '<<i%n;
					} 
					else{
						if(i%n==0){
							cout<<m<<' '<<i%n;
						}else cout<<m<<' '<<i%n;
					}
					break;
				}
			}
		}
	}
	return 0;
}
