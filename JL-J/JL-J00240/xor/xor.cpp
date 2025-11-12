#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500100],s,t,c,num;
//int rjz(int p){
	//bool o[10000000],m[10000000],h,j;
	//for(int i=1;p!=0;i++){
	//	if(p%2==0)m[i]=0;
	//	else m[i]=1;
	//	p=p/2;
	//	h=i;
	//}
	//for(int i=h;i>=1;i--){
	//	o[h-i]=m[i];
	//}
	//for(int i=1;i<=h;i++){
	//	j=j*10+o[i];
	//}
	//return j;
//}
//int yh(int a_,int b_){
	//int aa[1000000],bb[1000000];
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f;
	cin>>f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			s++;
			t=1;
		}
	}
	if(t==0){
		for(int i=1;i<=n;i++){
			//c=c+rjz(a[i]);
			num++;
			if(c==k){
				c=0;
				num=0;
				s++;
			}else if(c>k){
				
			}
		}
	}
	cout<<s;
	return 0;
}
