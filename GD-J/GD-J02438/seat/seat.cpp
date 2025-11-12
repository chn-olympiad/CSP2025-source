#include<bits/stdc++.h>
using namespace std;
int a,b[110]={0},n,m;
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
	a=b[1];
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==a){
			a=i;
			break;
		}
	}
	int k,k2,cnt;
	if(a%n==0){
		cnt=n;
		k2=a/n;
	}
	else{
		cnt=a%n;
		k2=a/n+1;	
	}
	if(k2%2==1){
		k=cnt;
	}
	else k=n-cnt+1;
	cout<<k2<<" "<<k;
	return 0;
}
