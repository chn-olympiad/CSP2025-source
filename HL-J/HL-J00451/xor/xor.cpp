#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=5e7+5;
int n,k,ans,cnt;
int a[N],b[N];
struct node{
	int l;
	int r;
}f[M];
bool cmp(node x,node y) {
	if(x.r!=y.r ) return x.r<y.r;
	else return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=a[i]^b[i-1];
		if(a[i]==k) {
			//ans++;
			f[++cnt].l=i;
			f[cnt].r=i;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((b[j]^b[i-1])==k) {
				f[++cnt].l=i;
				f[cnt].r=j;
			}
		}
	}
	sort(f+1,f+1+cnt,cmp);
	
	//for(int i=1;i<=cnt;i++)
	//	cout<<f[i].l<<' '<<f[i].r<<"\n";
	
	int lasl=0,lasr=0;
	for(int i=1;i<=cnt;i++){
		if(f[i].l>lasr) {
			lasr=f[i].r;
			ans++;
		}
	}
	cout<<ans;
	
	//for(int i=2;i<=n;i++)
	//	cout<<(b[i]^b[i-2])<<' ';
	
	
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
