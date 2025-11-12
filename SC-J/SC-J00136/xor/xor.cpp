#include<bits/stdc++.h>
using namespace std;
int x[2][10000],f[10000],s[2];
long long a[500005];
void js2(int a,int f){
	s[f]=0;
	int l[1000]={0};
	while(a!=0){
		l[s[f]]=a%2;
		a/=2;
		s[f]++;
	}
	for(int i=0;i<s[f];i++){
		x[f][i]=l[s[f]-1-i];
	}
}
void yh(){
	int a=min(s[0],s[1]);
	for(int i=0;i<a;i++){
		if(x[0][i]==x[1][i]){
			f[i]=0;
		}
		else{
			f[i]=1;
		}
	}
	if(s[0]>s[1]){
		for(int i=a;i<s[0];i++){
			f[i]=x[0][i];
		}
	}
	else if(s[0]<s[1]){
		for(int i=a;i<s[1];i++){
			f[i]=x[1][i];
		}
	}
}
int js10(){
	int b=max(s[0],s[1]),temps=0;
	for(int i=0;i<b;i++){
		temps*=2;
		temps+=f[i];
	}
	return temps;
}
int yh_h(int x,int y){
	int s=a[x];
	for(int i=x+1;i<=y;i++){
		js2(s,0);
		js2(i,1);
		yh();
		s+=js10();
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,s=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;i<n;j++){
			if(yh_h(i,j)==k){
				s++;
			}
		}
	}
	cout<<s;
	return 0;
}