#include <bits/stdc++.h>
using namespace std;
#define int long long 
// I hate xor!!!TwT
/*
4 2
2 1 0 3
*/
const int N=5e5+10;
int n,x;
int a[N];
int cnt;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>x;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(register int i=1;i<=n;i++){
		for(register int j=i;j<=n;j++){
			bool flag=false;
			int ans=0;
			for(register int k=i;k<=j;k++){
				if(k==i&&a[k]==x){
					flag=true;
					break;
				}
				else if(k==i){
					ans=a[k];
				}
				else{
					ans=ans xor a[k];
				}
				if(ans==x){
					flag=true;
					break;
				}
			}
			if(flag){
				cnt++;
				i=j+1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
