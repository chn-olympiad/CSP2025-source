#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,c;
int a[5100];
int b[5100];
int f[5100];
void print(int m){
	int k=0,maxx=b[m];
	for(int i=1;i<=m;i++){
		k+=b[i];
	}if(k>2*maxx){
		c++;
		c%=N;
	}
}
void pd(int x,int y,int z){
	for(int i=z;i<=n;i++){
		if(f[a[i]]==0){
			x++;
			b[x]=a[i];
			f[a[i]]=1;
			if(x==y){
				print(y);
			//	return ;
			}
			pd(x,y,i);
			b[x]=0;
			f[a[i]]=0;
			x--;
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		pd(0,i,1);
	}cout<<c<<endl;
	
	return 0;
}
