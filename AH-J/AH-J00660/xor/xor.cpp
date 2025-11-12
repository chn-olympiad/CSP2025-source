#include<bits/stdc++.h>
using namespace std;
#define N 500005
int yh(int x,int y){
	int k=0,b[25],f=0;
	while(x>0||y>0){
		b[k++]=(x%2+y%2)%2;
		x/=2;
		y/=2;
	}
	while(k--)
		f=f*2+b[k];
	return f;
}
int a[N],n,k,x,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int p=0;
		for(int j=i;j>x;j--){
			p=yh(p,a[j]);
			if(p==k){
				x=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
