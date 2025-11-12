#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10; 

int n,k,ans,l=-1;
int a[N],s[N],pos[20000000];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(pos,255,sizeof(pos));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
	pos[0]=0;
	for(int i=1;i<=n;i++){
		int f=s[i]^k;
		if(pos[f]+1>l&&pos[f]!=-1)
			ans++,l=i;
		pos[s[i]]=i;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
