#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int x,y;
cin>>x>>y;
int cnt=1;
int a[105];
int all=x*y;
for(int i=0;i<all;i++){
cin>>a[i];
}
for(int i=1;i<all;i++){
	if(a[i]>a[0]){
		cnt++;
	}
}
for(int k=0;k<x;k++){
	for(int l=0;l<y;l++){
		if(k*x+l==cnt){
			if(k%2==0){
				cout<<k+1<<" "<<l;
				break;
			}else{
				cout<<k+1<<" "<<y-l+1;
				break;
			}
		}
	}
}
return 0;
}
