#include<iostream>
#include<string>
using namespace std;
const long long P=998244353;
short int ok[1000];
int cok[1000];
int c[1000],maxc;
bool use[1000];
int pai[1000];
int n,m;
long long ans=0;
void dfs(int k){
	int nowm=0,failm=0;
	for(int i=1;i<k;++i){
		if(failm>=c[pai[i]]) failm++;
		else if(ok[i]==1) nowm++;
		else failm++;
	}
	//cout<<'*'<<failm<<' '<<nowm<<endl;
	if(nowm>=m){
		long long ps=1;
		for(long long i=2;i<=n-k+1;i++){
			ps=(ps*i)%P;
		}	
		//cout<<ps<<' '<<nowm<<' '<<k<<endl;
		ans=(ans+ps)%P;
		return ;
	}
	if(failm>maxc) return ;
	if(k==n+1){
		return ;	
	}
	for(int i=1;i<=n;++i){
		if(!use[i]){
			pai[k]=i;
			use[i]=1;
			//cout<<'.'<<k<<' '<<i<<endl;
			dfs(k+1);
			
			use[i]=0;
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string x;
	cin>>x;
	for(int i=n-1;i>=0;--i){
		ok[i+1]=x[i]-'0';
		cok[i+1]=cok[i+2]-ok[i+1]+1;
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
		maxc=max(c[i],maxc);
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
