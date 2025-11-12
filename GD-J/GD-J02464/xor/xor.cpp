#include<bits/stdc++.h> 
using namespace std;
int n,k,sum,tot[600005],a[500005],l,ans;
queue<int> q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	q.push(0);
	tot[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=sum^a[i];
		if(tot[sum^k]){
			ans++;
			while(!q.empty()){
				tot[q.front()]=0;
				q.pop();
			}
			sum=0;tot[0]=1;
			q.push(0);
		}
		else {
			tot[sum]++;
			q.push(sum);
		}
	}
	cout<<ans;
	return 0;
}
