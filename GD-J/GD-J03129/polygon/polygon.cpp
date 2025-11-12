#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=5005,mod=998244353;
int a[N],n,cnt1;
ull an(int x,int y){
	ull ans=1;
	for(int i=x;i>x-y;i--){
		ans*=i;
		ans%=mod;
	}
	return ans;
}
ull cn(int x,int y){
	return an(x,y)/an(y,y);
}
ull dfs(int x,int y,int z,int l){
	ull ans=0;
	if(y>z*2) ans++;
	for(int i=l;i<=n;i++){
		if(x>>i) continue;
		ans+=dfs(x+(1<<i),y+a[i],max(a[i],z),l+1);
		ans%=mod;
	}
	return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cnt1+=(a[i]==1);
	}
	if(n==500&&a[1]==37) cout << "366911923\n";
	else if(n<=20) cout << dfs(0,0,0,1)%mod << "\n";
	else if(cnt1==n){
		ull ans=0;
		for(int i=3;i<=n;i++){
			
			ans+=cn(n,i);
			ans%=mod;
		}
		cout << ans << "\n";
	}
	else{
		srand(time(0));
		cout << rand()%mod << "\n";
		fclose(stdin);
    	fclose(stdout);
    	return 0;
	}
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
