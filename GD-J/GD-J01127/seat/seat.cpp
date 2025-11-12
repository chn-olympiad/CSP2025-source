#include<bits/stdc++.h>
using namespace std;
int n,m,a[201],q,k,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>q;
	a[1]=q;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			k=i;
			break;
		}
	}
	k=n*m-k+1;
	while(s<k){
		s+=n;
		if(s>=k){
			if((s/n)%2==1){
				for(int i=1;i<=n;i++){
					if(s-n+i==k){
						cout<<s/n<<' '<<i;
						return 0;
					}
				}
			}
			if((s/n)%2==0){
				for(int i=1;i<=n;i++){
					if(s-n+i==k){
						cout<<s/n<<' '<<n-i+1;
						return 0;
					}
				}
			}
		}
	}
} 
