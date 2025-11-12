#include<bits/stdc++.h>
using namespace std;
int n,a[500010],k,ans,cnt,b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
    	if(a[i]==k){
    		ans++;
    		cnt=0;
    		continue;
		}
		b[++cnt]=a[i];
		for(int j=1;j<cnt;j++){
			b[j]^=a[i];
			if(b[j]==k){
				ans++;
				cnt=0;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
