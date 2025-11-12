#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int x;
double sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			sum=i;
			break;
		}
	}
	int y=ceil(1.0*sum/n);
	cout<<y<<" "; 
	if(y%2==0){
		cout<<(n-sum+n*(y-1))+1;
	}
	else{
		cout<<sum-n*(y-1);
	}
	return 0; 
}

