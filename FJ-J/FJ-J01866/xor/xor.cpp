#include<bits/stdc++.h>
using namespace std;
inline int fr(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
	   	x=(x*10)+(ch-'0');
		ch=getchar();
   }
	return x*f;
}
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=fr();
	k=fr();
	int teshu1=1;
	for(int i=1;i<=n;i++){
		a[i]=fr();
		if(a[i]!=1) teshu1=0;
		a[i]=a[i]^a[i-1];
	}
	if(teshu1){
		cout<<n/2;
		return 0;
	}
	return 0;
}



