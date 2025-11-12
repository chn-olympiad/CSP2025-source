#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
int n,k,a[500010],b[500010],pdA,pdB,ans=0,pd,sd[500010];
bool sf[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[i]=a[i];
		if(a[i]!=1){
			pdA=1;
		}
		if(a[i]>1){
			pdB=1;
		}
	}
	if(pdA==0){
		cout<<n/2;
		return 0;
	}else if(pdB==0){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1]){
					ans++;
					i++;
				}
			}
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
		}
		write(ans);
		return 0;
	}
	if(1){
		for(int i=1;i<=n;i++){
			for(int j=1;j+i-1<=n;j++){
				pd=0;
				int f=a[j];
				for(int z=j+1;z<=j+i-1;z++){
					if(sf[z]==true){
						pd=z;
						break;
					}
					f^=a[z];
				}
				if(pd!=0){
					j=pd;
					continue;
				}
				if(f==k){
					ans++;
					for(int z=j;z<=j+i-1;z++){
						sf[z]=true;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;	
}