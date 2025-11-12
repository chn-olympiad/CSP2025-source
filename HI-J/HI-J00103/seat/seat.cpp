#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	int s=a[1],ss=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]>s){
			ss++;
		}
	}
	if(ss/n%2==0){
		if(ss%n==0){
			cout<<ss/n<<" "<<1;
		}
		else{
			cout<<ss/n+1<<" "<<ss%n;
		}
	}
	if(ss/n%2!=0){
		if(ss%n==0){
			cout<<ss/n<<" "<<n;
		}
		else{
			cout<<ss/n+1<<" "<<n-ss%n+1;
		}
	}
	return 0;
}
