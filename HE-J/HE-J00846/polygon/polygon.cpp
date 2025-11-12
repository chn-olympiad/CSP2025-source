#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n,a[N];
bool flag;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag = true;
	}
	if(n<=3){
		if(n<3){
			cout<<0;
			return 0;
		}else{
			int res = 0,maxn=-1;
			for(int i=1;i<=n;i++){
				res+=a[i];
				maxn = max(maxn,a[i]);
			}
			if(res>=2*maxn){
				cout<<1;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}
	}else{
		if(!flag){
			cout<<n;
			return 0;
		}
	}
	cout<<'0';
	return 0;
} 
