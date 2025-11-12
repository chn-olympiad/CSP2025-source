#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
		if(a[i]==s){
			s=i;
			break;
		}
	int x=s/n,y=s%n;
	if(y==0){
		if(x%2==1)cout<<x<<" "<<n;
		else cout<<x<<" "<<1;
	}else{
		x++;
		if(x%2==1)cout<<x<<" "<<y;
		else cout<<x<<" "<<n-y+1;
	}
	return 0;
}
