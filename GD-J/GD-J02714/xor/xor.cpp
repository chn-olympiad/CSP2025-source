#include<bits/stdc++.h>
using namespace std;
struct js{
	bool a[21]={};
}k;
bool xdk(js a){
	for(int i=0;i<21;i++){
		if(a.a[i]!=k.a[i])return 0;
	}
	return 1;
}
js yh(js a,js b){
	js c;
	for(int i=0;i<21;i++){
		if(a.a[i]==b.a[i])c.a[i]=0;
		else c.a[i]=1;
	}
	return c;
}
js cj(int a){
	js b;
	int p=0;
	while(a){
		b.a[p]=a%2;
		a/=2;
		p++;
	}
	return b;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,ks,a,z=0;
	cin>>n>>ks;
	js s[n],zs;
	k=cj(ks);
	for(int i=0;i<n;i++){
		cin>>a;
		s[i]=cj(a);
//		for(int j=20;j>=0;j--)cout<<s[i].a[j];
//		cout<<endl;
	}
//	for(int j=0;j<21;j++)cout<<endl;
	int l=0,m=0;
	while(1){
		for(int j=0;j<21;j++)zs.a[j]=0;
		while(l<n){
			zs=yh(zs,s[l]);
//			for(int w=20;w>=0;w--)cout<<zs.a[w];
//			cout<<endl;
			if(xdk(zs)){
				z++;
				l++;
				break;
			}
			l++;
		}
		if(l==n){
			cout<<z;
			return 0;
		}
	}
	
	return 0;
} 
