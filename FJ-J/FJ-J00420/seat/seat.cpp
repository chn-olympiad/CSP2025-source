#include<bits/stdc++.h>
using namespace std;
const int N=150;
int x,y,n,m,fin;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	fin=a[1];
	sort(a+1,a+k+1);
	int flag=0;
	for(int i=1;i<=k;i++){
		if(a[i]==fin){
			flag=i;
			break;
		}
	}
	flag=k-flag+1;
	if(flag%n==0){
		x=flag/n;
	}
	else{
		x=flag/n+1;
	}
	flag=flag%n;
	if(flag==0){
		if(x%2==1){
			y=n;
		}
		else{
			y=1;
		}
	}
	else{
		if(x%2==1){
			y=flag;
		}
		else{
			y=n-flag+1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
