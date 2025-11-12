#include "bits/stdc++.h"
#define LL long long
#define VT vector
#define lst(type,size) new type[size]
using namespace std;
int n,k,l[10005];
int q(int x){
	for(int i=0;;i++){
		int t1,t2;
		t1= pow(2,i),t2= pow(2,i+1);
		if(x>=t1 && x<t2)return i;
		else if(x==t2)return i+1;
	}
}
int chint(int x[25]){
	int res=0;
	for(int i=0;i<25;i++){
		res+=pow(10,i)*x[i];
	}
	return res;
}
int ch10(int x){
	int tls[25]={0};int res=0;
	for(int i=24;i>=0;i--){
		int temp=x/pow(10,i);
		tls[i] = temp%10;
		res += pow(2,i)*tls[i];
	}
	return res;
}
int ch2(int x){
	int tres[25]={0};
	int tq=q(x);
	tres[tq]=1;
	if(x-pow(2,tq)==0){
		return chint(tres);
	}else{
		int ts=ch2(x-pow(2,tq));
		int tls[25]={0};
		for(int i=24;i>=0;i--){
			int temp=ts/pow(10,i);
			tls[i] = temp%10;
		}
		for(int i=0;i<25;i++){
			tres[i] = tres[i] or tls[i];
		}
	}
	return chint(tres);
}
int xorn(int x,int y){
	if(x==1 && y==0)return 1;
	if(x==0 && y==1)return 1;
	int a=ch2(x),b=ch2(y);
	int ta[25],tb[25],res[25]={0};
	for(int i=24;i>=0;i--){
		int temp=a/pow(10,i);
		ta[i] = temp%10;
	}
	for(int i=24;i>=0;i--){
		int temp=b/pow(10,i);
		tb[i] = temp%10;
	}
	for(int i=0;i<25;i++){
		if(ta[i] xor tb[i])res[i]=1;
	}
	int tt=chint(res);
	return ch10(tt);
}
int cal(int a,int b){
	int res=l[a];
	for(int i=a+1;i<=b;i++){
		res += xorn(res,l[i]);
	}
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&l[i]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int t =cal(i,j);
			if(t==k)ans++;
		}
	}
	cout<<ans;
}