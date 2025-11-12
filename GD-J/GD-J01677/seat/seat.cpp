#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,r;
int a[10000]={};
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
	if(i==1) r=a[i];
	int q=i;
	while(a[q]>a[q-1]&&q!=1){
		swap(a[q],a[q-1]);
		q--;
	}
}
//for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
int cnt=0;
for(int j=1;j<=n*m;j++){
	cnt++;
    if(a[j]==r) break;
 	
} 
//cout<<r<<" "<<cnt<<" ";
int aa=cnt%n;
int bb=cnt/n;
if(aa==0){
	if(bb%2==0){
		cout<<bb<<" "<<1;
	}
	else{
		cout<<bb<<" "<<n;
	}
}
else{
	if((bb+1)%2==0){
		cout<<bb+1<<" "<<n+1-aa;
	}
	else{
		cout<<bb+1<<" "<<aa;
	}
}
} 
