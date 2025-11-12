#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int n1=1;
	int m1=1;
	int a[(n*m+10)];
	for(int i=1;i<=(n*m);i++){
		cin>>a[i];
	}
	int oj=0;//判断偶数和奇数列 
	int me=a[1];
	for(int i=2;i<=(n*m);i++){
		
		if(a[i]>me){
			if(oj==0){
			if((n1+1)<=n){
				n1++;
			}
			else if((n1+1)>n){
				m1++;
				oj=1;
			}
		}
		else if(oj==1){
			if((n1-1)>=1){
				n1--;
			}
			else if((n1-1)<1){
				m1++;
				oj=0;
			}
		}
		
		}
	} 
	cout<<m1<<" "<<n1;
	  
	return 0;
}