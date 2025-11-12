#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010],c[1000010],vis[1000010][1000010],as[1000010][1000010];
int cy[100010];
int m,n,ans,k;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m == 1){
		cout<<n;
		return 0;
	}
	if(m<=n){
		for(int i = 1;i<=n;i++){
			ans*=i;
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

