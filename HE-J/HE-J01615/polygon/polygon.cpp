#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,ans;
long long a[N];
bool b[N];
struct node{
	long long y;
	long long h;
	long long m;
}fl[N];
int k=1;
void dfs(long long y,long long h,long long m){
	if(y>=3 && h>2*m){
		bool flag=true;
		for(int i=1;i<=k;i++){
			if(y==fl[i].y && h==fl[i].h && m==fl[i].m ){
				flag=false;
				break;
			}
		}
		if(flag){
			ans++;
			ans%=998244353;
			fl[k].y=y;
			fl[k].h=h;
			fl[k].m=m;
			k++;
		}
	}for(int i=1;i<=n;i++){
		if(b[i]){
			b[i]=false;
			dfs(y+1,h+a[i],max(m,a[i]));
			b[i]=true;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=true;
	}dfs(0,0,0);
	cout<<ans;
	return 0;
}
