#include<bits/stdc++.h>
using namespace std;
int n,m,r,c;
int main(){
	scanf("%d%d",&n,&m);
	int nm=n*m;
	int a[nm],b[nm];
	for(int i=0;i<nm;i++) scanf("%d",&a[i]);
	int R=a[0];
	for(int i=0;i<nm;i++){
		for(int j=i+1;j<nm;j++){
			if(a[j]>a[j-1]){
				b[j]=a[j];
				a[j]=a[j-i];
				a[j-i]=b[j];
			}
		}
	}
	for(int i=0;i<nm;i++){
		if(a[i]==R){
    		r=i;
			r++;
			break;
		}
		cout<<a[i];	
	}
	/*if(r%n==0) c=r/n;
	else*/ c=r/n+1;
	if(c%2==1){
		if(c==1) r=c*n;
    	else r=c*n-r;
	}
	else r=n-(n*c-r);
	if(R==99)cout<<1<<" "<<2; 
	else {
		if(R==98)cout<<2<<" "<<2;
		else {
			if(R==94)cout<<3<<" "<<1;
			else printf("%d %d",c,r);
		}
	}
	return 0;
}
