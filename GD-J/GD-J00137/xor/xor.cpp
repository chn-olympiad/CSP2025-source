#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k,a[MAXN],flag=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],cnt+=bool(a[i]),flag&=(a[i]<2);
	if(k==1 && flag) cout<<cnt;
	else if(k==0){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
			else if(a[i] && a[i+1]) i++,cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
