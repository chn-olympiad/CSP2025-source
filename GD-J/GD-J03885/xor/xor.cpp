#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+5;
const int INF=0x3f3f3f3f;
int a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
			}else{
				if(a[i]==1&&a[i+1]==1){
					i++,cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}else if(m==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

