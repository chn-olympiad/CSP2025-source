#include<bits/stdc++.h>
using namespace std;
int n,m,num2,c,r,nm;
struct node{
	int num,sum;
}b[105];
int cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin >> b[i].num;
		b[i].sum=i;
	}
	sort(b+1,b+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(b[i].sum==1){
			num2=i;
		}
	}
	if(num2%n==0){
		c=num2/n;
	}
	if(num2%n!=0){
		c=num2/n+1;
	}
	if(c%2==0){
		if(num2%n==0){
			r=1;
		}else{
			r=n-num2%n+1;
		}
	}
	if(c%2==1){
		if(num2%n==0){
			r=n;
		}else{
			r=num2%n;
		}
	}
	cout << c << " " << r;
	return 0;
} 
