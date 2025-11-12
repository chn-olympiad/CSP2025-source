#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int a[N];
int n,m,c,x,k,ansn,ansm;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	c = n*m;
	for(int i = 1;i<=c;i++){
		cin>>a[i];x = a[1];
	}
	sort(a+1,a+1+c,cmp);
	for(int i = 1;i<=c;i++){
		if(a[i] == x){
			k = i;
		}
	}
	if(k%n == 0){
		ansn = k/n;
		k = k-ansn*n;
	}
	else{
		ansn = k/n;
		k = k-ansn*n;
		ansn++;
	}
	if(ansn % 2 != 0){
		if(k == 0)ansm = n;
		else ansm = k%(n+1);
	}else{
		if(k == 0)ansm = 1;
		else ansm = n-k+1;
	}
	cout<<ansn<<" "<<ansm<<endl;
	return 0;
}
