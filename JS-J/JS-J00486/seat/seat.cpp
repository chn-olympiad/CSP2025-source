#include<bits/stdc++.h>
using namespace std;
long long n,m;//n hang m lie;
long long all,a,mapa[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    all = n*m;
    cin>>a;
    long long num = 0;
    for(int i = 0;i<all;i++){
		long long x;
		cin>>x;
		if(x>a) num++;
	}
	long long h=1,l=1;
	for(int i = 0;i<num;i++){
		if(l%2==1){ 
			if(h<n){
				h = h+1;
				}else{
					l = l+1;
					}
		}else if(l%2==0){
			 if(h>1){
				 h = h-1;
				 }else{
					 l = l+1;
					 }
		}
		}
	cout<<l<<' '<<h;
    return 0;
}
