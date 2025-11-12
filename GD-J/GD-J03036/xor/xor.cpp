#include <bits/stdc++.h>
using namespace std;
int main(){	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,now=0,cnt=0;
	cin>>n>>k;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	} 
	for(int i=1;i<=n;i++){
		if(now==0&&a[i]==0){
			continue;
		}
		else{
		now=(now^a[i]);
		if(now==k){
			cnt+=1;
			now=0;
		}
		}
		
	}
//	cout<<(5^4)<<endl;
		cout<<cnt<<endl;
	return 0;
}
