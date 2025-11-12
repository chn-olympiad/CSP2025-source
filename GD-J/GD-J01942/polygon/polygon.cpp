#include<fstream>

using namespace std;

ifstream cin("polygon.in");
ofstream cout("polygon.out");

long long ans=0;
long long mod=998244353;
long long a[5010];

bool check(long long cnt,long long big){
	if(cnt>big*2) return true;
	return false;
}
int n;

void bfs(int x,long long cnt,long long big){
	if(x>=3){
		if(check(cnt,big)){
			ans=ans%mod+1;	
		}
	}else{
		for(int i=x;i<=n;i++){
			if(a[i]>big){
				big=a[i];
			} 
			bfs(x+1,cnt+a[i]%mod,big%mod);
		}
	}
} 

int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	bfs(1,a[1],a[1]);
	cout<<ans;
	return 0;
}
