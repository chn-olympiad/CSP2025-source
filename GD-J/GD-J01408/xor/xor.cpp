#include <bits/stdc++.h>
using namespace std;
int n,k,a[5*114514],ans;
bool is[5*114514];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++)if(a[i]==k)ans++,is[i]=1;
	for(int i=1;i<=n;i++){
		int sum=a[i];
		if(is[i])continue;
		for(int j=i+1;j<=n;j++){
			if(is[j])break;
			sum=sum^a[j];
			if(sum==k){
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout << ans;
}
