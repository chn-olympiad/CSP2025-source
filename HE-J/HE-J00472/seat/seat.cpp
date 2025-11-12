#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k;
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i]; 
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			if(i%n!=0) {
				cout<<i/n+1<<" ";
				if((i/n+1)%2==1) cout<<i%n;
				else cout<<n-(i%n)+1;
			}
			else  if(i%n==0){
				cout<<i/n<<" ";
				if((i/n)%2==1) cout<<n;
				else cout<<1;
			}
			break;
		}
	}
	return 0;
} 
