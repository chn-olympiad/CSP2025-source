#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int x,y,n,m,ans=0;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1]){
			ans++;
		}
	}
	if(ans%n==0){
		x=ans/n;
	}else{
		x=ans/n+1;
	}
	y=ans-(x-1)*n;
	if(x%2==0){
		y=n-y+1;
	}
	cout<<x<<' '<<y<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
