#include <bits/stdc++.h>
using namespace std;
int n,m,b[10010],j,k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	j=b[1];
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==j){
			k=i;
			break;
		}
	}
	int a=k+n-1,c=a/n;
	cout<<a/n<<" ";
	if((a/n)%2!=0){
		if(k%n==0)cout<<n;
		else cout<<(k-(c-1)*n)%n;
	}
	else{
		if(k%n==0)cout<<1;
		else cout<<n+1-((k-(c-1)*n)%n);
	}
	return 0;
}
