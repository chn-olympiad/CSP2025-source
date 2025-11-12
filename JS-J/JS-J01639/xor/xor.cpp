#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],sum[500010],ans,s=1;
unordered_map<int,int>mp;
void reset(int ppp){
	mp.clear();
	ans++;
	s=ppp+1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i==1){
			sum[1]=a[i];
		}
		else{
			sum[i]=(sum[i-1]^a[i]);
		}
		//cout<<i<<endl;
	}
	//cout<<1<<endl;
	mp.clear();
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			reset(i);
			continue;
		}
		if(mp.find(sum[i]^k)!=mp.end()){
			reset(i);
			continue;
		}
		if(s!=1){
			if((sum[i]^sum[s-1])==k){
				reset(i);
				continue;
			}
		}
		else{
			if(sum[i]==k){
				reset(i);
				continue;
			}		
		}
		mp[sum[i]]++;
		//cout<<i<<endl;
	}
	printf("%d",ans);
	return 0;
}
