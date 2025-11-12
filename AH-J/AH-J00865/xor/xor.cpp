#include<bits/stdc++.h>
using namespace std;
int n,k,p1,m,ax=-2,v,l=1,r,d,h,num,f;
int cmp(int x)
{
	int u=0;
	while(x!=0){
		x/=2;u+=1;
	}
	u-=1;
	return u;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    m=k;
    int a[n+5]={},b[n+5][25]={},c[25],lx[n*(n+1)+5],rx[n*(n+1)+5];
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=ax) ax=a[i];
	}
	while(ax>0){ax/=2;v+=1;}v-=1;
	for(int i=1;i<=n;i++){
		while(a[i]>0){
			p1=cmp(a[i]);
			b[i][p1]=1;
			a[i]-=pow(2,p1);
		}
	}
	while(m>0){
		p1=cmp(m);
		b[n+1][p1]=1;
		m-=pow(2,p1);
	}
	/*
	for(int i=1;i<=n+1;i++){
		for(int j=0;j<=v;j++){
			cout<<b[i][j];
		}cout<<endl;
	}
    */
    for(int i=0;i<=n-1;i++){
		for(int j=1;j<=n-i;j++){
			f=1;
			for(int k=1;k<=ax;k++){
				h=0;
				for(int q=j;q<=j+i;q++) h+=b[q][k];
				if(h%2==1) c[k]=1;
				else c[k]=0;
				//cout<<c[k];
			}
			//cout<<endl;
			for(int k=1;k<=ax;k++){
				if(c[k]!=b[n+1][k]){
					f=0;break;
				}
			}
			if(f==1){
				lx[num]=l;rx[num]=r;num+=1;
			}
		}
	}
	num-=1;
	cout<<num;
	//for(int i=0;i<=num;i++) cout<<lx[i]<<" "<<rx[i]<<endl;
    return 0;
}
//Don't finish it in time
