#include<bits/stdc++.h>
using namespace std;
int T;
long long n,ans;
struct F{
	int a1,a2,a3;
}a[200005];
void dfs(int i,long long sum,int n1,int n2,int n3){
	if(i == n+1){
		ans = max(sum,ans);
		return ;
	}
	if(n1 < n/2){
		sum += a[i].a1;
		n1++;
		i++;
		dfs(i,sum,n1,n2,n3);
		i--;
		sum -= a[i].a1;
		n1--;
		
	
	}
	if(n2 < n/2){
		sum += a[i].a2;
		n2++;
		i++;
		dfs(i,sum,n1,n2,n3);
		i--;
		sum -= a[i].a2;
		n2--;
		
	}
	if(n3 < n/2){
		sum += a[i].a3;
		n3++;
		i++;
		dfs(i,sum,n1,n2,n3);
		i--;
		sum -= a[i].a3;
		n3--;
		
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		n=0,ans=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		}
		dfs(1,0,0,0,0);
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0 ;
}

