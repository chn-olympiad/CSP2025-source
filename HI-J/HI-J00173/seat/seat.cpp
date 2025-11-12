#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[105];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rf;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)rf=a[i];
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==rf){
			if(i%n==0){
				if((i/n)%2==1){
					cout<<i/n<<" "<<n;
				}else{
					cout<<i/n<<" "<<1;
				}
			}else{
				if((i/n)%2==0){
					cout<<i/n+1<<" "<<i%n;
				}else{
					cout<<i/n+1<<" "<<n-i%n+1;
				}
			}
		}
	}
	return 0;
} 
