#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,k,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
	for(int i=1;i<=k;i++) cin>>a[i];
	int wwq=a[1],ts=1;
	sort(a+1,a+k+1);
	reverse(a+1,a+k+1); 
	for(int i=1;i<=k;i++){
		if(a[i]==wwq){
			ts=i;
			break;
		} 
	}
	int roww=(ts-1)/n+1,col;
	cout<<roww<<" ";
	col=ts-(roww-1)*n;
	if(roww%2==0) col=m-col+1;
	cout<<col;
	return 0;
}

