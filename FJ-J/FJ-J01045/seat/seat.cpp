#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	int a[10000],b,d,s,k,l,c[12][12],g=0;
    cin>>k>>l;
    s=l*k;
    for(int i=0;i<s;i++){
    	cin>>a[i];
	}
	b=a[0];
	for(int i=0;i<=s-1;i++){
		for(int j=i+1;j<s;j++){
		if(a[i]<a[j]){
			d=a[i];
			a[i]=a[j];
			a[j]=d;
		}}
	}
	int p=0;
	for(int i=1;i<=l;i++){
		int j;
		if(i%2==1)
				j=1;
			else 
				j=k;
		for(;j<=k;){
			if(j==0){
				break;
			}
			c[i][j]=a[p];
			cout<<i<<" "<<j<<" "<<p<<" "<<a[p]<<endl;
			
		
			if(a[p]==b){
				cout<<i<<" "<<j;
				g=1;
				break;
			}
			p++;
			if(i%2==1)
				j++;
			else 
				j--;
			
		}
		if(g==1){
			break;
		}
	}
	return 0;
}
