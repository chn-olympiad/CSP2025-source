#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],ans,f1,f2=1,t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(i%n==1) f1++,t=!t;
		else{
			if(t) f2++;
			else f2--;	
		}
		if(a[i]==ans){
			cout<<f1<<" "<<f2;
			return 0;
		}
	}
}
