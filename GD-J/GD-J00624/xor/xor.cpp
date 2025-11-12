#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k,cnt;
ll a[500010],pre[500010],last;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>last;j--){
//			cout<<a[j]<<' ';
			int b=pre[i]^pre[j-1];
			if(b==k){
//				cout<<a[j]<<' '<<a[i]<<'\n';
//				cout<<j<<' '<<i<<' '<<b<<'\n';
				cnt++;
				last=i;
//				cout<<j<<'\n';
				break;
			}
		}
//		cout<<'\n';
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
