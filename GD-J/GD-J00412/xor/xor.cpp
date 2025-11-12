#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],d[500005],ans;
unordered_map<int,bool>ma;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],d[i]=(d[i-1]^a[i]);
	int l=0;
	for(int i=1;i<=n;i++){
		if((d[i]^d[l])==k||ma[(d[i]^d[l]^k)]==1){
			l=i;ans++;unordered_map<int,bool>().swap(ma);
		}
		else ma[(d[i]^d[l])]=1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//水题 前三题加起来45min 
