#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,k,ans=0;
int a[N];
int zh(bool p[],int x){
	int g=1,sm[25];
//	memset(sm,0,sizeof(sm));
	while(x>0){
		p[g]=x%2;
		x/=2;
//		cout<<p[g]; 
		g++;
	}
	g--;
//	for(int i=1;i<=g;++i){
//		p[i]=sm[g-i+1];
//		cout<<p[i]; 
//	}
//	cout<<endl;
	return g;
}
int zh2(bool o[],int h){
	int g=1,s=0;
	for(int ii=1;ii<=h;++ii){
		s+=o[ii]*g;
		g*=2;
	}
	return s;
}
int yh(int u,int v){
//	cout<<u<<" "<<v<<endl;
	bool uu[25],vv[25],c[25];
	memset(c,0,sizeof(c));
	memset(uu,0,sizeof(uu));
	memset(vv,0,sizeof(vv));
	int u1=zh(uu,u);
	int v1=zh(vv,v);
	int z=max(u1,v1);
	for(int j=z;j>=1;--j){
		if(uu[j]!=vv[j])
			c[j]=1;
//		cout<<c[j];
	} 
//	cout<<endl<<endl;
	return zh2(c,z);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		int u=a[i];
		for(int j=i;j<=n;++j){
			if(i==j){
				u=a[j];
			}
			else  u=yh(u,a[j]);
			if(u==k)  ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//光荣的石室 