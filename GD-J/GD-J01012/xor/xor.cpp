#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int ma=5e5+5;
int a[ma],cnt[ma],n,k,sum;
void dfs(int f){
	for(int i=f+1;i<=n;i++){
		if(cnt[i]>f){
			sum++;
			dfs(i);
			break;
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(cnt,-1,sizeof(cnt));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ll num=a[i];
		if(num==k){
			cnt[i]=i;
			continue;
		}
		for(int j=i-1;j>=1;j--){
			num^=a[j];
			if(num==k){
				cnt[i]=j;
				break;
			}
		}
	}

	for(int i=1;i<=n;i++){
		if(cnt[i]!=-1){
			sum++;
			dfs(i);
			break;
		}
	}
	cout<<sum;
	return 0;
}

