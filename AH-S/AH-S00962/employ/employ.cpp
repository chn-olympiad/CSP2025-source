#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int mod=998244353;

int n,m;
int ans;
int c[MAXN];
int a[MAXN];
bool used[MAXN];
long long sum=1;
string s;

bool check(){
	int cnt=0,cnt1=0;
	for(int i=1; i<=n; i++){
		if(c[a[i]]<=cnt1 || s[i]=='0')	cnt1++;
		else cnt++;
		if(cnt>=m) return 1;
	}
	return 0;
}
void dfs(int k){
	if(k==n+1){
		if(check()==1) ans++;
		return;
	}
	for(int i=1; i<=n; i++){
		if(used[i]==1) continue;
		used[i]=1;
		a[k]=i;
		dfs(k+1);
		used[i]=0;
		a[k]=0;
	}
}

void answer(){
	for(int i=1; i<n; i++){
		sum=(sum*(1ll*i))%(1ll*mod);
	}
	printf("%Illd\n" ,sum);
}

int main(){
	freopen("employ.in","r",stdin);		//zhuyi!!!!!
	freopen("employ.out","w",stdout);
	
	scanf("%d%d" ,&n,&m);
	cin>>s;
	s=' '+s;
	for(int i=1; i<=n; i++) scanf("%d" ,&c[i]);
	sort(c+1,c+n+1);
	
	if(n<=10) {
		dfs(1);
		printf("%d\n" ,ans%mod);
		return 0;
	}
	if(m==n){
		int flag=0;
		for(int i=1; i<=n; i++){
			if(s[i]=='0' || c[i]==0){
				flag=1;
				break;
			}
		}
		if(flag==1) printf("0\n");
		else answer();
		return 0;
	}
	if(m==1){
		answer();
		return 0;
	}
	
	int flag=0;
	for(int i=1; i<=n; i++){
		if(s[i]=='0'){
			flag=1;
			break;
		}
	}
	if(flag==0){
		int cnt=0;
		for(int i=1; i<=n; i++){
			if(c[i]==0) cnt++;
		}
		if(n-cnt<m){
			printf("0\n");
		}
		answer();
		return 0;
	}
}
