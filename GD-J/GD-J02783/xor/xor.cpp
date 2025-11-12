#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(ch>='0'&&ch<='9');
	return f?-x:x;
}
int n,m,f[500001],s;
map<int,bool>a,b;
signed main(){
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;i++)f[i]=rd()^f[i-1];a[0]=1;
	for(int i=1;i<=n;i++){
		if(s%2){
			if(b[m^f[i]])s++,b=a,a[f[i]]=1;
			else b[f[i]]=1;
		}
		else{
			if(a[m^f[i]])s++,a=b,b[f[i]]=1;
			else a[f[i]]=1;
		}
	}
	cout<<s;
	return 0;
}
