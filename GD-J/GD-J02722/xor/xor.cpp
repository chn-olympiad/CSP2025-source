#include<bits/stdc++.h>
using namespace std;
#define int long long
/*         RP++!        */
int n,k;
//int f[500005];
int ans = 0;
//int sum[500005];
//struct node{
//	int l;
//	int r;
//}p[500005];

stack<int> q1;
void check(int x){
	if(x == k){
		while(!q1.empty()) q1.pop();
		ans++;
		return ;
	}
	int sum = x;
	stack<int> q2;
	if(!q1.empty()){
		while(!q1.empty()){
			int temp = q1.top();
			q1.pop();
			q2.push(temp);
			int aabb = sum ^ temp;
			if(aabb == k){
//				cout<<sum<<" "<<temp<<" "<<aabb<<"\n";
				while(!q1.empty()) q1.pop();
				ans++;
				return ;
			}else{
				sum = aabb;
			}
		}
		while(!q2.empty()){
			q1.push(q2.top());
			q2.pop();
		}
		q1.push(x);
	}else q1.push(x);
	return ;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		check(x);
		
//		sum[i] = sum[i-1] ^ f[i]; 
	}
//	for(int len=1;len<=n;len++){
//		for(int i=1;i<=n-len+1;i++){
//			if(sum[i])
//		}
//	}
//	cout<<endl;
	cout<<ans;
	return 0;
}

