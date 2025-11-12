#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000010],ans=0,v[1000010];
int main() {
	ios::sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		v[i]=0;
	}
	if(n<=1000) {
		for(int cd=0; cd<=n; cd++) {
			for(int i=1; i<=n-cd; i++) {
				int jl=0,ioe=0;
				for(int j=i; j<=i+cd; j++) {
					if(v[j]==1) {
						ioe=1;
						break;
					}
					jl^=a[j];
				}
				if(jl==k&&ioe==0) {
					ans++;
					for(int j=i; j<=i+cd; j++) {
						v[j]=1;
					}
				}
			}
		}
	cout<<ans;
	}else{
		cout<<"0";
	}
	return 0;
}/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/