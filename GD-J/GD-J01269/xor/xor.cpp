#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int a[500005];
bool v[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	a[0]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(m==a[i])ans++;
		else if(m==0){
			if(a[i]==a[i-1]&&v[i-1]!=1){
				ans++;
				v[i]=1;
				v[i-1]=1;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
