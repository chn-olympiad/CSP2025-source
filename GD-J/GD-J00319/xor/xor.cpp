//xor
#include<bits/stdc++.h>
using namespace std;
long long a[500007];
struct node{
	long long l,r;
	bool operator < (const node &a) const{
		return r>a.r;
	}
};
priority_queue<node>q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0,lr=0;
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i=1; i<=n; i++){
		long long sum=a[i];
		if(sum==k){
		    q.push({i,i});
			continue;
		}
		for(int j=i+1; j<=n; j++){
			sum^=a[j];
			if(sum==k){
				q.push({i,j});
				break;
			}
		}
    }
    while(q.size()){
    	node x=q.top();
    	q.pop();
    	if(x.l>lr) ans++,lr=x.r;
	}
	cout<<ans;
	return 0;
}
