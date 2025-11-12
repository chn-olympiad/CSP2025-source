#include<bits/stdc++.h>
using namespace std;
int a[1000],n,k;
int pan(int b,int c){
	int l=0;
	for(int i=b;i<=c;i++){
		l=l^a[i];
	}
	return (l==k);
}
int main(){
freopen("xor.in","r",stdin); 
freopen("xor.out","w",stdout);
cin>>n>>k;
bool sss;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
int lll=1;
int zui=-1000;
int fangxian=0;
int zf;
int you=1;
for(;;){
	zui=100000;
	zf=100000;
	sss=0;
	for(int i=you;i<=n;i++){
		for(int f=i;f<=n;f++){
			if(pan(i,f)&&(f-i+1<zui||(f<zf&&f-i+1==zui))){
				zui=f-i+1;
				zf=f;
				sss=1;
			}
		}
	}
	if(sss&&fangxian<=n){
		fangxian++;
		you=zf+1;
	}else{
		break;
	}
}
cout<<fangxian;
return 0;
}
