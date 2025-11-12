#include<bits/stdc++.h>
using namespace std;
int a[5010][5010],n,k,b[5010]; 
int yihuo(int x,int y){
	int r[30],s,d=1,h=0;
	for(int i=1;x!=0&&y!=0;i++){
		if(x%2!=y%2){
			r[i]=1;
		}else{
			r[i]=0;
		}
		x=x/2;
		y=y/2;
		s=i;
	}
	for(int i=1;i<=s;i++){
		h=h+r[i]*d;
		d=d*2;
	}
	return h;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int c=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i][i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j+i<=n;j++){
			int q=0;
			for(int x=j;x<=j+i;x++){
				if(b[x]==1){
					q=1;
					break;
				}
			}
			if(q==0){
				if(i!=0){
					a[j][j+i]=a[j][j+i-1]+yihuo(j+i-1,j+i);	
				}
			 		if(a[j][j+i]==k){
				 	c++;
			 		for(int z=j;z<=j+i;z++){
			 			b[z]=1;	
					}		
			 	}	
			}
		}
	}
	cout<<c;
	return 0;
} 