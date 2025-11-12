#include<bits/stdc++.h>
using namespace std;
int n,m,a,b[150],ans,w,j=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	w=b[1];
	sort(b+1,b+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(b[i]==w){
			if(j%n==0){
				if((j/n)%2==1){
					cout<<j/n<<" "<<n;
				}else{
					cout<<j/n<<" "<<"1";
				}
			}else{
				if((j/n)%2==1){
					cout<<j/n+1<<" "<<n-j%n+1;
				}else{
					cout<<j/n+1<<" "<<j%n;
				}
			}
			
			break;
		}
		j++;
	}
	return 0;
} 