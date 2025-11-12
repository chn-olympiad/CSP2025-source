#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int o=a[1];
	sort(a+1,a+n*m+1);
	int k;
	for(int i=1;i<=n*m;i++){
		if(a[i]==o){
			k=n*m-i+1;
			break;
		}
	}
	int x=k/n,y=k%n;
	cout<<k<<endl;
	if(y==0){
		if((x+1)%2==0)
			cout<<x<<" "<<n;
		else cout<<x<<" "<<1;
		return 0;
	}
	else {
		if((x+1)%2==1)
			cout<<x+1<<" "<<y;
		else cout<<x+1<<" "<<n-y+1;
	}
	return 0;
}

