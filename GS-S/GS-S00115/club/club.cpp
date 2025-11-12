#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+5;

int t,n;
int a1[N],a2[N],a3[N];

int ans;
bool f3=0;
void dfs(int step,int n1,int n2,int n3,int sum){
	//cout << step << endl;
	if(step>n){
		ans = max(ans,sum);
		return ;
	}
	
	if(2*(n1+1) <= n) dfs(step+1,n1+1,n2,n3,sum+a1[step]);
	if(2*(n2+1) <= n) dfs(step+1,n1,n2+1,n3,sum+a2[step]);
	if(2*(n3+1) <= n && !f3) dfs(step+1,n1,n2,n3+1,sum+a3[step]);
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		int z2=1,z3=1;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]!=0)z2=0;
			if(a3[i]!=0)z3=0;
		}
		ans=0;
		if(z2 && z3){
			sort(a1+1,a1+1+n);
			reverse(a1+1,a1+1+n);
			for(int i=1;i<=(n/2);i++){
				ans+=a1[i];
			}
			cout << ans << endl;
			continue;
		}
		
		f3=0;
		if(!z2 && z3) f3=1;
		dfs(1,0,0,0,0);
		cout << ans << endl;
	}
	
	return 0;
}



