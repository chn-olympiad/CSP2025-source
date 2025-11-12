#include<bits/stdc++.h>
using namespace std;
struct pu{
	long long total;
	long long length;
	int now;
};
int n;
long long k;
long long max_n=0;
queue<pu> q;
void bfs(vector<int> v){
	while(!q.empty()){
		auto a=q.front();
		long long sum=a.total;
		long long l=a.length;
		int nowp=a.now;
		q.pop();
		if(sum==k){
			max_n=max(max_n,l);
		}
		if(nowp+1<n){
			pu x={sum+v[nowp+1],l+1,nowp+1};
			q.push(x);
			pu y={sum-v[nowp+1],l+1,nowp+1};
			q.push(y);
			pu z={0,0,nowp+1};
			q.push(z);
			
		}else{
			break;
		}
		
		
	}
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	pu a={v[0],1,0};
	q.push(a);
	pu b={-v[0],1,0};
	q.push(b);
	pu c={0,0,0};
	q.push(c);
	bfs(v);
	cout<<max_n;
	return 0;
}
