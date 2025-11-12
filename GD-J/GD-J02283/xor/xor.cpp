#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b=0;
int chack(int x,int y){
	int xh[21]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},zh=0;
	for(int i=x;i<=y;i++){
		int c[21]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},d=1,g=a[i];
		while(g){
			c[d]=g%2;
			g/=2;
			d++;
		}
		for(int i=1;i<=20;i++){
			if(xh[i]==c[i]) xh[i]=0;
			else xh[i]=1;
		}
	}
	for(int i=1;i<=20;i++) zh+=pow(2,i-1)*xh[i];
	if(zh==k) return 1;
	else return 0;
}
	
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(chack(i,j)){
				b++;
				i=j+1;
				j=j+1;
			}
		}
	}
	cout<<b;
	return 0;
} 
