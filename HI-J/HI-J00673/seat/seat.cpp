#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x[101],y;
    for(int i=1;i<=n*m;i++){
    	cin>>x[i];
	}
	y=x[1];
	int nn=1,mm=1;
	for(int i=2;i<=n*m;i++){
		if(x[i]>y && mm%2==1){
			nn++;
			if(nn>n){
				nn--;
				mm++;
			}
		}
		else if(x[i]>y && mm%2==0){
			nn--;
			if(nn<1){
				nn++;
				mm++;
			}
		}
	}
	cout<<mm<<" "<<nn;
return 0;
}
