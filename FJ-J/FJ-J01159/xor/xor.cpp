#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int y;
	cin>>y;
	int maxn=y;
	if(k==0||k==1){
		for(int i=1;i<n;i++){
			int x;
			cin>>x;
			if(x>maxn){
				maxn=x;
			}
		}
	}
	if(k==0){
		cout<<maxn;
	}else if(k==1){
		cout<<(maxn/2)<<endl;
	}
	return 0;
}
