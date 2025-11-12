#include <bits/stdc++.h>
using namespace std;

const int N=5e5+100;
int n,k,ans;
int a[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0) cout<<1;
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]!=0){
				ans++;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
