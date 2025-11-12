#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+(c-'0'),c=getchar();
	return x*f;
}
#define N 500010
int n,k;
int a[N],b[N],c[N];
bool flag=1;
vector<int>t;
int maxt=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=a[i]^b[i-1];
//	for(int i=1;i<=n;i++)if(a[i]>1)flag=0;
//	if(flag){
//		int sum=0;
//		for(int i=1;i<=n;i++)sum+=a[i];
//		if(k==1)cout<<sum;
//		else cout<<sum/2;
//	}
//	else{
	for(int i=0;i<=n;i++)c[i]=b[i]^k;
	for(int i=0;i<=n;i++)maxt=max(maxt,max(b[i],c[i]));
	t.resize(maxt+10,-1);
	t[c[0]]=0;
	int lst=0,ans=0;
	for(int i=1;i<=n;i++){
		if(t[b[i]]>=lst){
			lst=i;ans++;
		}
		t[c[i]]=i;
	}
	cout<<ans;
//	}
	return 0;
}

