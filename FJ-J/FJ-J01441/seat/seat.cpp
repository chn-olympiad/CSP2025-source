#include <bits/stdc++.h>
using namespace std;
int n,m,cd[105],o,xiaoR,j;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cd[i];
	}
	xiaoR=cd[1];
	sort(cd+1,cd+1+n*m,cmp);
	cout<<endl;
	while(true){
		o++;
		if(cd[o]==xiaoR){
			break;
		}
	}
	if(o%n==0){
		j=o/n;
	}else{
		j=o/n+1;
	}
	cout<<j<<" ";
	if(j%2==1){
		if(o<=n||o%n==0){
			cout<<o/j;
		}else{
			cout<<o%j;
		}
	}else{
		cout<<j*n-o+1;
	}
	return 0;
}

