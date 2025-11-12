#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,R;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int i;
	for(i=1;i<=n*m;i++){
		cin>>a[i]; 
	}
	R=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(i=1;i<=n*m;i++){
		if(a[i]==R){
			if(i%n!=0){
				cout<<i/n+1<<" ";
				if((i/n+1)%2==0) cout<<n-i%n+1;
				else cout<<i%n;
				return 0;
			}
			else{
			    cout<<i/n<<" ";
				if((i/n)%2==0) cout<<1;
				else cout<<n;
			}
		}
	}
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
