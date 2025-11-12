#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],b[25],c[25],ins=0,ans=0,huk;
void yhh(int a1,int b1){
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int q=0,p=0,ulb=1,ub=0,len;
	while(a1){
		++q;
		b[q]=a1%2;
		a1/=2;
	}
	while(b1){
		++p;
		c[p]=b1%2;
		b1/=2;
	}
	if(p>q)len=p;
	else len=q;
	for(int i=len;i>=1;--i)if(b[i]!=c[i])ub+=(1<<(len-i+1));
	huk=ub;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		huk=a[i];
		if(huk==k){
			ins=i;
			ans++;
		}
		for(int j=i-1;j>ins;--j){
			yhh(huk,a[j]);
			if(huk==k){
				ins=i;
				ans++;
				break;
	        }
		}
	}
	printf("%d",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}