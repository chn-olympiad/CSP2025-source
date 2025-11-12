#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			int ys=i%n;
			int s=(i/n)+1;
			if(i<=n){
				cout<<1<<" "<<i;
				return 0;
			}
			if(s%2==0){
				cout<<s<<" "<<n-ys+1;
			}
			else{
				cout<<s<<" "<<ys;
			}
			break;
		}
		
	}
	return 0;
}