# include <bits/stdc++.h>
using namespace std;
int n,m;
bool v[6000];
int a[500005],pre[500005],dp[500004],is1,is0;
struct asd{
	int l,r,len;
}f[500004];
int jsq;
bool cmd(asd a,asd b){
	if(a.l!=b.l) return a.l<b.l;
	else return a.len<b.len;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int q=1;q<=n;q++){
		cin>>a[q];
		if(a[q]==1) is1++;
		if(a[q]==0) is0++;
		
		pre[q]=a[q]^pre[q-1];
	}
	if(is1==n){
		if(m==0){
			cout<<is1/2<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i]=a[i];
		for(int j=i;j<=n;j++){
			if(j!=i) dp[j]=dp[j-1]^a[j];
			
			
			if(dp[j]==m&&a[j]!=0&&a[i]){
				jsq++;
				f[jsq].l=j;f[jsq].r=i;f[jsq].len=i-j;
			}
		}
	}
//	sort(f+1,f+n,cmd);
//	for(int q=1;q<=jsq;q++){
//		cout<<f[q].l<<" "<<f[q].r<<endl;
//	} 
	cout<<jsq;
	return 0;
}
//
