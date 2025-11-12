#include<bits/stdc++.h>

using namespace std;
int n,k,a[500005],ans=0;
void yh(int x,int y){
	int a[500005],b[500005],i=0,j=0,c[500005],d[500005],e[500005];
	while(x>0){
		a[++i]=x%2;
		x/=2;
	}
	while(y>0){
		b[++j]=y%2;
		y/=2;
	}int s=0,h=0;
	for(int l=i;l>=1;l--)c[++s]=a[l];
	for(int l=j;l>=1;l--)d[++h]=b[l];
	for(int l2=1;l2<=max(i,j);l2++){
		if(c[l2]==b[l2])e[l2]=0;
		else e[l2]=1;
	}
	for(int l2 =1;l2<=max(i,j);l2++){
		ans=ans*2+e[l2];
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}int sum=0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			yh(i,j);
			if(ans==k)sum++;
		}
	}
	cout<<sum;
	return 0;
}
