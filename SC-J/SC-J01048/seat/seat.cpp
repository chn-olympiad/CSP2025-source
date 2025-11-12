#include<bits/stdc++.h>
using namespace std;
int a[105],m,n,o,mo,no;
bool pd(int x,int y){
	return x>y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=m*n;i++){
	cin>>a[i];
}
o=a[1]; 
sort(a+1,a+m*n+1,pd);
for(int i=1;i<=m*n;i++){
	if(a[i]==o){
		if(i>=n){
			if(i%n!=0){
				mo=i/n+1;
			}else{
				mo=i/n;
			}		
		}else{
			mo=1;
		}
		if(mo%2==0){
			no=n-(i-n*(mo-1))+1;
		}else{
			no=i-n*(mo-1);
		}
	}
}
cout<<mo<<" "<<no;
return 0;
}