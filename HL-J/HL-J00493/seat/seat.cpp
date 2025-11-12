#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w,b,c=0,a[101];
	cin>>n>>m;
	b=n*m;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	w=a[1];
	sort(a,a+b,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				c++;
				if(a[c]==w){
								
					cout<<i<<" "<<j;
					return 0;			
				}

			}
		}else{
			for(int j=m;j>=1;j--){
				if(a[c]==w){
					cout<<i<<" "<<j;
					return 0;					
				}
				c++;
			}
		}
	}
	return 0;
}