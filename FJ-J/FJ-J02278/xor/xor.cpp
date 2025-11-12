#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],cntq;
vector<int> aq;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			aq.push_back(0);
			for(int j=0;j<aq.size();j++){
				aq[j]^=a[i];
				if(aq[j]==k){
					cntq++;
					aq.clear();
					break;
				}
			}
		}
		cout<<cntq;
	return 0;
}
