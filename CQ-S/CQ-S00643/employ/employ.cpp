#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500,mod=998244353;
int n,m,c[N],sp_0[N],num_0=0,leat[N],ans=0,jj=0,num_qpl=0,szqpl[N];
char s[N];
bool b[N];
void qpl(){
	if(num_qpl==n){
		jj=0;
		for(int i=1;i<=n;i++){
			if(jj>=c[szqpl[i]]||s[i]=='0'){
				jj++;
			}
//			cout<<szqpl[i]<<" ";
		}
//		cout<<"\n";
		if(n-jj==m){
			ans++;
//			cout<<"++\n";
		}
		ans%=mod;
	}
	else{
		for(int i=1;i<=n;i++){
			if(b[i]==0){
				b[i]=1;
				szqpl[++num_qpl]=i;
				qpl();
				b[i]=0;
				num_qpl--;
			}
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	qpl();
	printf("%lld\n",ans);
	return 0;
}

