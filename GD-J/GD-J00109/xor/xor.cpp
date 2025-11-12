#include<bits/stdc++.h>
using namespace std;
bool bl[1050000];
queue<int> q;
int n,k,a[500005],qz[500005],ans,x;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	qz[0]=0;
	bl[0]=true;
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]^a[i];
		x=qz[i]^k;
		if(bl[x]){
			ans++;
			while(!q.empty()){
				bl[q.front()]=false;
				q.pop();
			}
			bl[0]=true;
			qz[i]=0;
		}
		q.push(qz[i]);
		bl[qz[i]]=true;
	}
	cout<<ans;
	return 0;
}
