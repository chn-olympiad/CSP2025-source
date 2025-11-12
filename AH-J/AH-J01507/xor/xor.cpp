#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
int a[N],s[N],n,k;
bool p[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	int ans=0,fl=1;
	bool pd=false;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		pd=false;
		for(int j=fl;j<=i;j++){
			int d=s[i]^s[j-1];
			if(d==k){
				ans++;
				fl=i+1;
				pd=true;
			}
			if(pd) break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
