#include<bits/stdc++.h>
using namespace std;
int n,k,maxn,sum,e,z;
int xx[50002];
int yihuo(int a,int b){
	int w[16],shu=0,jia;int a1=a;int b1=b;
	for(int i=0;a1||b1;i++){
		if(a1%2!=b1%2){
			w[i]=1;
		}a1/=2;b1/=2;
	}
	for(int i=0;i<16;i++){
		if(w[i]==1){
			jia=1;
			for(int j=i;j>0;j--){
				jia*=2;
			}
			shu+=jia;
		}
	}
	return shu;
}
bool bi(int wei){
	int qian=xx[wei];
	if(qian==k){
		e=wei+1;
		return true;
	}else{
		while(qian!=k){
			wei++;
			if(wei>n){
				return false;
			}else{
				qian=yihuo(qian,xx[wei]);
			}
		}e=wei+1;
		return true;
	}
}
void sou(int wei){
	if(wei>n){
		return ;
	}else{
		z=wei;
		if(bi(z)){
			sum++;
			sou(e);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>xx[i];
	}sou(1);
	cout<<sum;
	return 0;
} 