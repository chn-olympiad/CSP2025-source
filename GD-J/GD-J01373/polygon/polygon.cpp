#include<bits/stdc++.h>
using namespace std;

int n,a[5005],f[5005];
long long ans,N=998244353;
int sefind(int x,int y,int z,int h){
	int l=0;
	for(int i=h+1;i<=n;i++){
		int b=max(x,a[i]);
		if(y+a[i]>b*2){
			l++;
			int c=y+a[i];
			if(z<n) return sefind(b,c,z+1,h);
			else return l;
		}
	}
}
int find(int x,int y){
	int aa=0;
	int sum=3;
	int b,c;
	b=max(x,y);
	for(int i=x+1;i<=n;i++){
		b=max(b,a[i]);
		if(x+y+a[i]>b*2){
			aa++;
			c=x+y+a[i];
			if(sum<n) return sefind(b,c,sum+1,x);
			else return aa;
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
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans+=find(i,j);
		}
	}
	cout<<ans%N-1;
	return 0;
}
