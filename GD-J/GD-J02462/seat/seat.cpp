#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
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
	int q=a[1],wz=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			wz=i;
			break;
		}
	}
	if(wz%n==0){
		if((wz/n)%2==1){
			cout<<(wz/n)<<" "<<(n);
		}
		else{
			cout<<(wz/n)<<" "<<1;
		}
		return 0;
	}
	else{
		if((wz/n)%2==0){
			cout<<(wz/n+1)<<" "<<(wz%n);
		}
		else{
			cout<<(wz/n+1)<<" "<<(n-(wz%n)+1);
		}
	}
}
