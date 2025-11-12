#include<bits/stdc++.h>
using namespace std;
int n,k,sum1=0,sor,cor;
int a[510000],c[510000],d[22];
int b[510000][22];
void ch(int x){
	int y=a[x],cnt=0;
	while(y>=0){
		cnt++;
		b[x][cnt]=y%2;
		y/=2;
	}
	c[x]=cnt-1;
}
int count(int x,int y){
	memset(d,0,sizeof(d));
	sor=0;
	int z=1;
	for(int i=1;i<=max(c[x],c[y]);i++){
		if(b[x][i]==b[y][i]){
			d[i]=0;
		}
		else{
			d[i]=1;
		}
	}
	for(int i=1;i<=max(c[x],c[y]);i++){
		sor+=d[i]*z;
		z*=2;
	}
	return z;
}

int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ch(i);
	}
	
	for(int i=1;i<=n;i++){
		cor=a[i];
		for(int j=i;j<=n;j++){
			if(cor==k){
				i=j+1;
				sum1++;
				break;
			}
			cor=count(cor,j);
		}
	}
	printf("%d",sum1);
	return 0;
}
