#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10009];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	int num=n*m;
	sort(a+1,a+num+1);
	int b=0;
	for(int i=n*m;i>0;i--){
		if(a[i]==r) b=i;
	}
	for(int i=1;i<=n*m;i++){
		if(b<=n){
			cout<<b<<" "<<1;
			break;
		}
		else if(b%n!=0){
			if((b/n+1)%2!=0){
				cout<<b%n<<" "<<b/n+1;
			}
			else cout<<m<<" "<<b/n+1;
			break;
		}
		else {
			cout<<m<<" "<<b/n;
			break;
		}
	}
	
	return 0;
}

