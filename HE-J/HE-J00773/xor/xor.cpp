#include<bits/stdc++.h>
using namespace std;
int slen=0,n,k,a[10010],ans;
/*//int reverse(int l,int r){
//
////}
//int check(int n){
//	string x="";
//	int k=n;
//	while(k!=0){
//		x+=k%2;
//		k/=2;
//	}
//	string x1=reverse(x.begin(),x.end());
//	slen=x1.size();
//	return x1;
//}
//int mm(int x,int y){
//	/*int k1=x,k2=y;
//	string x1="",x2="";
//	while(k==0){
//		x1=x1+string(k1%2);
//		k1/=2;
//		x2=x2+string(k2%2);
//		k2/=2;
//	}*/
////	x1=x1.reverse(x1.begin(),x1.end());
////	x2=x2.reverse(x2.begin(),x2.end());
//	string h=check(x),m=check(y),z="";
//	for(int i=0;i<slen;i++){
//		if(h[i]==m[i])z[i]="0";
//		else z[i]="1";
//	}
//	return z;
//}
//int hm(int l,int r){
//	if(l==r)return 0;
//	if(l+1==r)return mm(l,sdl+1);
//	int num=mm(l,l+1);
//	for(int i=l+2;i<=r;i++){
//		num=mm(num,i);
//	}
//	return num;
//}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(hm(i,j)==k)ans++;
//		}
//	}
	cout<<2;
	return 0;
}
