#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt;
int t[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	int maxn=0;
	for(int j=3;j<=n;j++){
		for(int i=1;i<=n;i++){
			maxn=0;
			int nums=0;
			for(int k=0;k<j;k++){
				maxn=max(maxn,t[i+k]);
				nums+=t[i+k];
			}
			if(nums>maxn*2){
				cnt++;
				cnt%=998244353;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
