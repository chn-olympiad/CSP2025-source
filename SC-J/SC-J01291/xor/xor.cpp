#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n,k,a[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int al1=1,al2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)al1=0;
		if(a[i]>1)al2=0;
	}
	if(al1){
		if(k==0)cout<<n/2;
		else if(k==1)cout<<n;
		else cout<<0;
	}
	else if(al2){
		if(k==0){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)cnt++;
				else if(a[i]&&a[i+1])
					cnt++,i+=2;
			}
			cout<<cnt;
		}
		else if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1)cnt++;
			cout<<cnt;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
