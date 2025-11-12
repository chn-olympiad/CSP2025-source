#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int b[n*m];
	int cj,num=0;
	cin>>cj;
	b[0]=cj;
	for(int i=1;i<n*m;i++){
		cin>>b[i];
	}
	sort(b,b+n*m,cmp);
	for(int i=0;i<n*m;i++){ 
		if(b[i]==cj){
			num=i;
			break;
		}
	}
	num+=1;
	cout<<num/m<<" "<<n-num%n;
	return 0;
}
/*
2 2
99 98 97 100
*/

