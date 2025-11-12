#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("saet.out","w",stdout);
    cin>>n>>m;
    int s=1;
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i>1&&a[1]<a[i]){
			s++;
		}
    }
    
    int num=0,cut;
    int j,i;
    for(i=1;i<=n;i++){
		if(i==1){
			cut=0;
		}
		else{
			cut=1;
		}
		for(j=cut;j<=m;j++){
			if((num++)==s){
				cout<<i<<" "<<j;
			}
		}
		i++;
		if(i>n){
			break;
		}
		for(j=m;j>=1;j--){
			if((num++)==s){
				cout<<i<<" "<<j;
			}
		}
	}
	
    return 0;
}
