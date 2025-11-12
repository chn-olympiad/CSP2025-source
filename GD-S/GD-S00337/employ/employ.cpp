#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=550,M=998244353;
int n,sum[N],c[N],m;
LL ans;
string s;
bool v[N];
void dfs(int k,int id,int res){
	//cout<<k<<endl;
	if(id>=n){
		if(res>=m) ans=(ans+1)%M;
		//cout<<res<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			if(v[i]==0){
				v[i]=1;
				if(sum[id]<c[i]&&s[id+1]=='1'){
					dfs(i,id+1,res+1);
					v[i]=0;
				}
				else{
					dfs(i,id+1,res);
					v[i]=0;
				}
				v[i]=0;
			}
		}
	}
	return ;
}
vector <int> one;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flag=1;
	cin>>s;
	s="%"+s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1];
		if(s[i]=='0'){
			sum[i]++;
		}
		else{
			flag=0;	
			one[++cnt]=i;
		}
	}
	if(flag){
		int cnt=1;
		ans=1;
		while(cnt<=n){
			ans=(ans*cnt)%M;
			cnt++;
		}
		printf("%lld",ans%M);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(m==1){
		for(int i=1;i<=cnt;i++){
			for(int j=1;i<=n;j++){
				if(sum[one[i]-1]>=c[j]){
					ans++;
				}
			}
		}
		printf("%lld",ans%M);
		return 0;
	}
	for(int i=1;i<=n;i++){
		v[i]=1;
		dfs(i,1,1);
		v[i]=0;
	}
	printf("%lld",ans%M);
	return 0;
} 
