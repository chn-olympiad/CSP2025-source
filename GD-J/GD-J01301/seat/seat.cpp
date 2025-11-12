#include<bits/stdc++.h>
using namespace std;
int n,m,xm,arr[10001],xp;
int cmp(int x,int y){
	return x>y;
}
int li(){
	if(xp<=n)return 1;
	if(xp%n==0){
		return xp/n;
	}else{
		return xp/n+1;
	}
}
int ha(){
	if(xp<=n)return n;
	if(li()%2==0){//偶数列 
		if(xp%n==0)return 1;
		else return (n+1)-xp%n;
	}else{//奇数列 
		if(xp%n==0)return n;
		else return xp%n;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	xm=arr[1];
	sort(arr+1,arr+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(arr[i]==xm)xp=i;
	}
	cout<<li()<<" "<<ha(); 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
