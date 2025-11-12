#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long a[10005];
bool b[10005];
bool ff;
bool find(){
	long long sum=0,t=0;
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			sum+=a[i];
			t=max(t,a[i]);
		}
	}
	if(sum>t*2){
		ans++;	
		ans%=998244353;
		return 1;
	} 
    else return 0;
}
void dfs(int d,int x){
	if(d==0){
		if(!find()) ff=1;
		return;
	}
	for(int i=x;i<=n;i++) {
		b[i]=1;
		dfs(d-1,i+1);
		b[i]=0;
		if(ff==1&&d==1){
			ff=0;
			break;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++) dfs(i,1);
    cout<<ans;
    fclose(stdin);
	fclose(stdout);
}
