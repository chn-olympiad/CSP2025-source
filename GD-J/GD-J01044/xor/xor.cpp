#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;    
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			continue;
		}
		int s=a[i];
		for(int j=i+1;a[j]!=k;j++){
			s=(s^a[j]);
			if(s==k){
				cnt++;
				i=j+1;
				break;
			}
		}
		
	}
	cout<<cnt;
	return 0;
}

