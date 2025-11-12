#include<bits/stdc++.h>
using namespace std;
	char a[10010];
	long long b[100010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(m==n){
	long long cnt=0;
		for(long long i=0;i<n;i++){
			if(a[i]=='0'){
				cout<<0<<endl;
				return 0;
			}
		}
		for(long long i=1;i<=n;i++){
			if(b[i]==0){
				cout<<0<<endl;
				return 0;
			}
		}
		for(long long i=1;i<=n;i++){
			cnt*=cnt;
			cnt%=998244353;
		}
		cout<<cnt<<endl;
	}
	else{
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			if(b[i]!=0){
				cnt++;
			}
		}
		for(long long i=1;i<=n;i++){
			cnt*=cnt;
			cnt%=998244353;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
