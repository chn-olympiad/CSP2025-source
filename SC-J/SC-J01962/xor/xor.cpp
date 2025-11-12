#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=5e5+10;

int n,k;
int a[N];

void case1(){
	int ans=0;
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		} 
		cout<<ans;
		return ;
	}
	else {
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			else {
				int cnti=0;
				for(int j=i;j<=n;j++){
					cnti++;
					if(a[j+1]==0){
						i=j;
						break;
					}
				}
				ans+=cnti/2;
			}
		}
		cout<<ans;
		return ;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flagA=1,flagB=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flagA=0;
		else if(a[i]>1) flagB=0;
	}
	if(k==0&&flagA) cout<<n/2;
	else if(k<=1&&flagB) case1();
	return 0;
}


