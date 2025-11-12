#include<bits/stdc++.h>
using namespace std;
int a[250];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1];
	sort(a+1,a+1+(n*m),greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			int p;
			if(i%n==0){
				p=i/n;
				if(p%2==1) cout<<p<<" "<<m;
				else cout<<p<<" "<<i%m+1;
			}
			else{
				p=i/n+1;
				if(p%2==1) cout<<p<<" "<<i%m;
				else cout<<p<<" "<<m-i%m+1<<" ";
			}
			
		}
	}

 return 0;
}

