#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int n,m,q;
int a[110];
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int s=a[1];
    sort(a+1,a+(n*m)+1);
    for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			q=i;
			break;
		}
	}
    if(q%n==0){
		if(q/n%2==0) cout<<q/n<<' '<<1;
		else cout<<q/n<<' '<<n;
	}else{
		cout<<q/n+1<<' '<<q%n;
	}
	return 0;
}
