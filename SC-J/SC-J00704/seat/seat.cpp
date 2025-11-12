#include<bits/stdc++.h>
using namespace std;
int a[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int h=n*m;
	cin>>a[1];
	int s=a[1];
	for(int i=2;i<=h;i++)cin>>a[i]; 
	sort(a,a+h+1);
	int k;
	for(int i=1;i<=h;i++){
		if(a[i]==s){
			k=i;
			break;
		}
	}
	if(k%n!=0)cout<<n-k/n<<" ";
	else cout<<n-k/n+1<<" ";
	if((k%n)%2==0)cout<<n-k%n;
	else cout<<1+k%n;
	return 0;
}