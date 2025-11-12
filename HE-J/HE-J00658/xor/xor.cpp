#include<bits/stdc++.h>
using namespace std;

int pre[500005];
int a[500005];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		pre[1]=a[1];
		pre[i]=pre[i-1]^a[i];
	}
	int ans;
	int tot=0;
	for(int len=1; len<=n; len++){
		for(int i=1; i<=n-len+1; i++){
			ans=pre[i]^pre[i+len-1];
			if(ans==k) tot++;
		}
	}
	cout<<tot<<endl;
	return 0;
}
