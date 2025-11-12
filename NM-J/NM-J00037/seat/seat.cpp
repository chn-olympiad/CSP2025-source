#include<bits/stdc++.h>
using namespace std;
int a[101];
int n,m;
int c,r,k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int j=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==j){
			j=i+1;
			break;
		}
	}
	cout<<(j+2)/3<<' '<<j%3;
	return 0;
}

