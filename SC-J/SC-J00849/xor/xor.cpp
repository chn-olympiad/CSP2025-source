#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int a[N];
int f[N],b[N],b1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		bool p=0;
		if(a[i]==k) f[i]+=1,b1=0,p=1;
		else{
			int c=k^a[i];
			for(int j=1;j<=b1;j++){
				if(b[j]==c){
					f[i]+=1;
					p=1;
					b1=0;
					break;
				}
			}
		}
		if(p==0){
			for(int j=1;j<=b1;j++){
				b[j]=b[j]^a[i];
			}
			b[++b1]=a[i];
		}
	}
	printf("%d",f[n]);
	return 0;
}

