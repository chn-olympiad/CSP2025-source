#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int n,k,a[N],s[N],sum=0,ans=0;
struct node{
	int l,r;
}b[N*N];
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return f*s;
}
bool cmp(node a,node b){
	if(a.l!=b.l) return a.l<b.l;
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			int x=s[j]^s[i-1];
			if(x==k){
				b[++sum]={i,j};
			}
		}
	sort(b+1,b+sum+1,cmp);
	int r=1,r1=b[r].r+1;ans=1;
	while(r<=sum){
		while(r+1<=sum&&b[r].l<r1) r++;
		r1=b[r].r+1;ans++;
		if(r==sum) break;
		//cout<<r<<endl;
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
}
//o(n2)
/**/
