#include<bits/stdc++.h>
using namespace std;
int N=105;
int main(){
	//freopen("seat.in","r",stdin)
	//freopen("seat.out","w",stdout)
	int n,m,a[N];
	cin>>n>>m>>a[N];
	if(n*m<a[N]){
		for(int i=1;i<=n*m;i++){
		    i+=n;
		}
	}
	cout<<n<<" ";
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
