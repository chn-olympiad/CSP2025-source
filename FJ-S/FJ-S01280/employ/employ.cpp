#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,ans;
int a[505],c[505],p[505],f[505];
unsigned long long frc[505];
bool flag=0;

bool check(){
	int pre=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0 || pre>=c[p[i]]){
			pre++; continue;
		}
		cnt++;
		
	}
	
	return cnt>=m;
}


void dfs(int k,int v){
	p[k]=v;
	
	if(k==n){
//		for(int i=1;i<=n;i++) cout<<p[i]<<" ";
//		cout<<'\n';
		if(check()) ans++;
		ans%=MOD;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			dfs(k+1,i);
			f[i]=0;
		}
	}
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
		if(!a[i]) flag=1;
	}
	
	frc[0]=1;
	for(int i=1;i<=n;i++){
		frc[i]=i*frc[i-1];
	}

	for(int i=1;i<=n;i++) cin>>c[i];
	//int p=clock();
	if(!flag){//特殊性质A:全是1
		int ans=(frc[n]%MOD)/((frc[m]*frc[n-m])%MOD)%MOD;
		cout<<ans%MOD;
	}
	
	dfs(0,0);//爆搜
	cout<<ans%MOD; 
	//cout<<"time:"<<clock()-p;
	return 0;
}
