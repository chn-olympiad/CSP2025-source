#include<bits/stdc++.h>
using namespace std;
int n,m,a[201],r,x,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			k=n*m-i+1;
			if(k%n!=0&&k/n+1!=1){
				cout<<k/n+1<<" ";
				if(n-((k/n+1)*n-k)==1&&n!=2)cout<<1;
				else cout<<n-((k/n+1)*n-k)+1;
			}
			else if(k%n==0&&k/n!=1){
				cout<<k/n<<" ";
				cout<<n-(n-((k/n+1)*n-k))+1;
			}
			else if(k/n==0){
				cout<<1<<" ";
				cout<<n-(n-((k/n+1)*n-k))+1;
			}
			else if(k/n==1){
				cout<<1<<" ";
				cout<<n;
			}
			break;
		}
	}
	
	return 0;
}
