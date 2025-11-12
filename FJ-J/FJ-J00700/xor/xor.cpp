#include<bits/stdc++.h>
using namespace std;
int n,k;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		int cnt;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(x==0){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}
