#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in" ,"r",stdin);
	freopen("seat.out" ,"w",stdin);
	int n,m,o,t,e=0;
	cin>>n>>m;
	int a[m*n+5]={ };
	for(int i=1;i<m*n;i++){
		int k;
		cin>>k;
		a[i]=k;
		
	}o=a[1];
	for(int i=1;i<m*n;i++){
		if(a[i]<a[i+1]){
			t=a[i+1];
			a[i+1]=a[i];
			a[i]=t;
		}
	}
	for(int i=1;i<m*n;i++){
		if(a[i]==o){
			if(i<3){
				cout<<1<<" "<<i; 
			}else{
				cout<<2<<" "<<i;
			}
		}
	}
	return 0;

}
