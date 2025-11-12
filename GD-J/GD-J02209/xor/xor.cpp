#include <bits/stdc++.h>
using namespace std;
vector<int>a(500010);
int main(){
	freopen("xor.in",'r',stdin);
	freopen("xor.out",'w',stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int now=0,ans=0;
	for(int i=0;i<n;i++){
		now=now^a[i];
		if(now==k){
			ans++;
			now=0;
		}
	}
	cout<<ans;
	return 0;
} 
