#include<bits/stdc++.h>
using namespace std;
int n,m,r,b,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[m*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}r=a[0];
	for(int i=0;i<n*m;i++){
		int max=0;
		for(int j=i;j<n*m;j++){
			if(max<a[j]){
				max=a[j];
				c=j;
			}
		}b=a[i];a[i]=max;a[c]=b;
	}b=0;
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			b++;
			break;
		}b++;
	}int x,y;cout<<b<<endl;
	while(x*m<b){
		x++;
	}if(x%2!=0){
		if(b%m==0){
			y=m;
		}else{
			y=b%m;
		}
	}else{
		y=m-b%m+1;
	}cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
