#include <bits/stdc++.h>
using namespace std;
long long n,k,arr[500005],cnt,f;
bool flag[500005];

void find(int x=1){
	if(x>n) return ;
	for(int i=1;i<=n;i++){
		//cout<<x<<' ';
		if(!flag[i]){
			if(i+x<=n){
				int ans=0;
				for(int j=i;j<i+x;j++){
					if(flag[j]){
						i+=j;
						break;
					}
					ans=ans^arr[j];
					//cout<<arr[j]<<endl;
				}
				//cout<<ans<<endl;
				if(ans==k){
					for(int j=i;j<i+x;j++){
						flag[j]=1;
					}
					cnt++;
				}
				//cout<<cnt<<endl;
			}
		}
	}
	find(++x);
	return ;
}

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	find();
	cout<<cnt;
	return 0;
}
