#include<bits/stdc++.h>
using namespace std;
int x,y,a[105];
int n,m;
int R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<=c;i++){
		cin>>a[i];
		if(i==1) R=a[i];
	}
	sort(a+1,a+c+1);
	for(int i=1;i<=c;i++){
		if(a[i]==R){
			R=c-i+1;
			break;
		} 
	}
	/*cout<<R<<endl;
	if(R%n==0) cout<<R/n<<" "<<n;
	else cout<<R/n+1<<" "<<R%n;
	*/
	//cout<<R<<endl;
	int v=R/n;
	if(R%n==0){
		cout<<R/n<<" ";
		if(v%2==0) cout<<1;
		else cout<<n;
	} 
	else{
		cout<<R/n+1<<" ";
		if(v%2==1) cout<<n-R%n+1;
		else cout<<R%n;
	} 
	
	
	return 0;
}
/*
2 2 99 100 97 98
2 2 98 99 100 97
3 3 94 95 96 97 98 99 100 93 92

*/

