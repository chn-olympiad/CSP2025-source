#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=105;
int a[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int rr=a[1];
	sort(a+1,a+m*n+1,cmp);
	int k=0;
	for(int i=1;i<=m;i++){
		bool f=true;
		if(i%2==1){
			for(int j=1;j<=n;j++){
				k++;
				if(a[k]==rr){
					cout<<i<<' '<<j;
					f=false;
					break;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				k++;
				if(a[k]==rr){
					cout<<i<<' '<<j;
					f=false;
					break;
				}
			}
		}
		if(f==false) break;
	}
	
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/