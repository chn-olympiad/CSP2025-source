#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freeopen("seat.in","r",stdin);
	freeopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;//n行m列 
	int a[150],r,num,l,h;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];if(i==1) r=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			num=i;
			break;
		}	
	}
	if(num%n>0){
		l=num/n+1;
	}else{
		l=num/n;
	}
	if(l%2==0){
		if(num%n==0){
			h=1;
		}else{
			h=n-num%n+1;
		}
	}else{
		if(num%n==0){
			h=n;
		}else{
			h=num%n;
		}
	}
	cout<<l<<' '<<h;
	return 0;
} 