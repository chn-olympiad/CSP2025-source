#include<bits/stdc++.h>
using namespace std;
int a,zs,b[5005];
bool c[5005];
long long d[5005];
const int q=998244353;
void zh(int x,int y){
	for(int i=1;i<=a;i++){
		if(c[i]==0&&i>b[x-1]){
			c[i]=1;
			b[x]=i;
			if(x==y){
		long long mmax=0,zhe=0;
		for(int i=1;i<=y;i++){
			zhe+=d[b[i]];
			mmax=max(mmax,d[b[i]]);
		}
		if(zhe>(2*mmax)){
		zs=(zs+1)%q;
		}
	}else zh(x+1,y);
	c[i]=0;
		}
	}
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>a;
for(int i=1;i<=a;i++){
	cin>>d[i];
}
for(int i=3;i<=a;i++){
	zh(1,i);
}
cout<<zs<<endl;
return 0;
}
