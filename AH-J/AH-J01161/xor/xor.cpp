#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int m=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i])m--;
	}
	if(k==1)cout<<m;
	else{
		int cnt=0,p=0;
		for(int i=1;i<=n;i++){
			if(!a[i])p=0,cnt++;
			else if(a[i]&&!p)p=1;
			else if(a[i]&&p)p=0,cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
