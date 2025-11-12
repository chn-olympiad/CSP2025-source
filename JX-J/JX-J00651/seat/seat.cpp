#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
}
int x=a[1];
sort(a+1,a+1+n*m,cmp);
for(int i=1;i<=n*m;i++){
	if(a[i]==x){
		int x=i/n;
		int y=i%n;
		if(y==0){
			cout<<x<<" ";
			if(x%2==0){
			cout<<n;
			}else{
				cout<<1;
			}
		}else{
			cout<<x+1<<" ";
			if(x%2==0){
			cout<<y;
			}else{
				cout<<n-y+1;
			}
		}
		return 0;
	}
}
return 0;
}
