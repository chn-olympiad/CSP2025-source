#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=n%2;
	if(m==1 && n==1){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n*m;i++){
		if(b==a[i]){
			if(n==1){
				cout<<1<<" "<<i;
				return 0;
			}
			else if(m==1){
				cout<<i<<" "<<1;
				return 0;
			}
			else if(a[i+1]==0){
				if(n==0){
					cout<<n<<" "<<m;
					return 0;
				}
				else{
					cout<<1<<" "<<m;
				}
			}
		}
	}
	return 0;
}
