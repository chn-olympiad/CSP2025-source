#include<iostream>
using namespace std;
int n,m,cnt=0,j=0;
int a[10001],fla[1001]={0};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	fla[0]=1;
	for(int i=0;i<m*n;i++){
		for(int b=1;b<n*m;b++){
			if(a[b-1]<a[b]){
				 swap(fla[b-1],fla[b]);
				 swap(a[b-1],a[b]);
				 }
		}
	}
	while(fla[j]!=1){
		j++;
	}
	/*if(((j-)/4+1)%2==1){
		
	}*/
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int h=1;h<=n;h++){
				cnt++;
				if(cnt==j+1) cout<<i<<" "<<h;
			}
		}
		else{
			for(int h=n;h>0;h--){
				cnt++;
				if(cnt==j+1) cout<<i<<" "<<h;
			}
		}
	}
}
