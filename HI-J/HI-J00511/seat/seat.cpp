#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+78]={0};
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	int b=a[0];
	sort(a+0,a+n*m,cmp);
	for(int i=0;i<m*n;i++){
		if(a[i]==b){
			cout<<i/n+1<<" ";
			if(i/n%2==0){
				cout<<i%n+1;
			}else{
				cout<<n-i%n;
			}
		}
	}
	return 0;
}

