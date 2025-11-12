#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001];
bool cmp(int x,int b){
	return x>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a1,p=n*m;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a,a+p+1,cmp);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i+j]==a1){
				cout<<i+1<<' '<<j+1;
				return 0;
			}
		}
	}
	return 0;
}
