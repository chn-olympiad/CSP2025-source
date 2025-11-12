#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--){
		if(a[i]==k){
			int o=t-i+1;
			cout<<(o+n-1)/n<<" ";
			if(((o+n-1)/n)%2){
				cout<<(o-1)%n+1;
			}
			else{
				cout<<n-((o-1)%n+1)+1;
			}
		}
	}
	return 0;
}
