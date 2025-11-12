#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    int s=1;
    int a;cin>>a;
    for(int i=1;i<n*m;i++){
    	int b;
    	cin>>b;
    	if(b>a)s++;
	} 
	if(s%n==0){
		cout<<s/n<<" ";
		if(s/n%2==1){
			cout<<n;return 0;
		}
		cout<<1;
	}
    else{
    	cout<<s/n+1<<" ";
    	if((s/n+1)%2==1){
			cout<<s%n;return 0;
		}
		cout<<n-s%n+1;
	}
	return 0;
}
