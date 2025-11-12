#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[501];
long long tot;
long long cnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			cnt++;
		}
	}
	tot=1;
	for(long long i=1;i<=cnt;i++){
		tot*=i;
		tot%=998244353;
	}
	cout<<tot;
	return 0;
}
