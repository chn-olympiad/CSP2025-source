#include<bits/stdc++.h>
using namespace std;
int b[400];
int n,m,g,maxx=-100,pp,kh,kl;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		int l=0;
		cin>>l;
		b[l]=l;
		if(i==0) g=l;
	}
	for(int i=1;i<=n*m;i++){
		if(maxx<b[i-1]){
			maxx=b[i-1];
			if(maxx==g){
				pp=i;
			}
		}
	}
	
	int ss,bc=1;
	for(int i=1;i<=pp;i++){
		
		if(bc%2!=0){
			if(ss%n==0){
				ss=n;
				bc++;
			}else ss=i%n;
			
		}
		if(bc%2==0){
			if(ss%n==0){
				ss=1;
				bc++;
			}else ss=n-i%n+1;
		}
	}
	
	if(pp%n==0){
		kl=pp/n;
	}else kl=pp/n+1;
	
	cout<<kl+1<<" "<<ss+1;
	return 0;
}
