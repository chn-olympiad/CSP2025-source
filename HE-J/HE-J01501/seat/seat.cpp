#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[n*m+10],i,j,k=0;
	cin>>n>>m;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
		    cin>>a[k];
		    k++;
	    }
	}
    int num=1;
	for(i=1;i<k;i++){
		if(a[i]>a[0]){
			num++;
		}
	}
	int x=ceil(num*1.0/n);
	cout<<x<<' ';
	if(x%2==0){
		cout<<n-(num-x-1);
	}else{
		cout<<num-n*(x-1);
	}
}
