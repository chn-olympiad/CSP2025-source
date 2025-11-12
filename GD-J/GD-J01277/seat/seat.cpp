#include<bits/stdc++.h>
using namespace std;
int n,m,c,l,a[105],k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out ","w",stdout);
	cin>>n>>m>>c;
	l=n*m;
	a[0]=c;
	for(int i=1;i<l;i++){
		cin>>a[i];
	}
	sort(a,a+l,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[k]==c){
					cout<<i<<" "<<j;
					return 0;
				}else{
					k++;
				}
			}
		}else{
			for(int j=m;j>0;j--){ 
				if(a[k]==c){
					cout<<i<<" "<<j;
					return 0;
				}else{
					k++;
				}
			}
		}
 	}
	return 0;
}
