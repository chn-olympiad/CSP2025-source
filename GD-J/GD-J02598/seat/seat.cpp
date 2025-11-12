#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
int a[N],num,id,k=1;
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
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			id=i;
			break;
		}
	}
	while(id>n){
		k++;
		id-=n;
	}
	if(k%2==1){
		cout<<k<<" "<<id;
	}else{
		cout<<k<<" "<<n-id+1;
	}
	return 0;
}
