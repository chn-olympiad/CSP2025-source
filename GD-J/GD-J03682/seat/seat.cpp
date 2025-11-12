#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
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
	int h=a[1],num=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(h==a[i]){
			num=i;
		}
	}
	int u=num/n;
	if(u*n<num)u++;
	if(num%n==0){
		num=n;
	}
	else{
		num%=n;
	}
	//cout<<u<<" "<<num<<endl; 
	if(u%2==0){
		cout<<u<<" "<<m-num+1;
	}
	else{
		cout<<u<<" "<<num;
	}
	return 0;
}
