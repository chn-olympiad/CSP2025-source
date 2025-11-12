#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[111];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int p=a[1];
//	cout<<p<<endl;
	sort(a+1,a+n*m+1,greater<int>());
	int q=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			q=i;
			break;
		}
	}
//	cout<<q<<endl;
	int x=q/n;
	q=q%n;
	int y=0;
	if(q==0){
		if(x%2==1) y=n;
		else y=1;
	}else{
		x++;
		if(x%2==1)y=q;
		else y=n-q+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
