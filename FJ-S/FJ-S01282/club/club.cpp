#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int in(){
	char c=getchar();
	int k=0;
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}return k;
}
struct nobe{
	int v,pos;
}b[4];
bool cmp(nobe x,nobe y){
	return x.v<y.v;
}
int t,n,sum[4];
int op1[N],op2[N],op3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("a.txt","r",stdin);
//	freopen("b.txt","w",stdout);
	t=in();
	while(t--){
		n=in();int ans=0;
		sum[1]=sum[2]=sum[3]=0;
		for(int i=1;i<=n;i++){
			b[1].v=in();b[2].v=in();b[3].v=in();
			b[1].pos=1;b[2].pos=2;b[3].pos=3;
			sort(b+1,b+4,cmp);
			int j=b[3].pos;
			ans+=b[3].v;sum[j]++;
			if(j==1)op1[sum[j]]=b[2].v-b[3].v;
			if(j==2)op2[sum[j]]=b[2].v-b[3].v;
			if(j==3)op3[sum[j]]=b[2].v-b[3].v;
		}sort(op1+1,op1+1+sum[1]);
		sort(op2+1,op2+1+sum[2]);
		sort(op3+1,op3+1+sum[3]);
		for(int i=n/2+1;i<=sum[1];i++)ans+=op1[i];
		for(int i=n/2+1;i<=sum[2];i++)ans+=op2[i];
		for(int i=n/2+1;i<=sum[3];i++)ans+=op3[i];
		cout<<ans<<'\n';
	}
	return 0;
} 
