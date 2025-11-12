#include <bits/stdc++.h>
using namespace std;
//easy?
int n,a[100005],k,ans;
bool vis[100005];

void solveXor(int l,int r){
	int ret=a[l];
	for(int i=l+1;i<=r;i++)
		ret^=a[i];
	if(ret==k){
		ans++;
		for(int i=l;i<=r;i++)
			vis[i]=true;
	}
}

bool isEmpty(int l,int r){
	for(int i=l;i<=r;i++)
		if(vis[i])return false;
	return true;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w".stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n-i;j++)
			if(isEmpty(j,j+i))
				solveXor(j,j+i);
	cout<<ans;
	return 0;
}
//very easy!!!