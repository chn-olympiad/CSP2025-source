#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,R,h=0,l=0,y;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==R){
			R=i;
			break;
		}
	}
	y=R%n;
	if(y==0){
		l=R/n;
	}else{
		l=R/n+1;
	}
	if(l%2==0){
		if(y==0){
			h=1;
		}else{
	    	h=n-R%n+1;	
		}
	}else{
		if(y==0){
			h=n;
		}else{
			h=y;
		}
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
