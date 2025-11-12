#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,f=0,aa=1,bb=1,ff=0;
	cin>>a>>b;
	int n[a*b+2],r;
	for(int i=1;i<=a*b;i++){
		cin>>n[i];
	}
	r=n[1];
	for(int i=1;i<=a*b;i++){
		if(f==1)break;
		int zd=INT_MIN,zdj;
		for(int j=1;j<=a*b;j++){
			if(n[j]>zd){
				zd=n[j];
				zdj=j;
			}
		}
		
		if(zd==r){
			cout<<bb<<" "<<aa;
			f=1;
			break;
		}
		n[zdj]=-1;
		if(ff==0){
			aa+=1;
		}
		else if(ff==1){
			aa-=1;
		}
		if(aa>a){
			bb+=1;
			aa=a;
			ff=1;
		}
		else if(aa<1){
			bb+=1;
			aa=1;
			ff=0;
		}
		//cout<<bb<<" "<<aa<<" "<<ff<<endl;
	}
	return 0;
}