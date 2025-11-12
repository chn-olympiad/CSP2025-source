#include <bits/stdc++.h>

using namespace std;
int a[500001]={};

struct node{
	int s;
	int e;
	int w;
};
queue<node> q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=0,k=0;
	cin>>n>>k;
	int ans=0,num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push({i,i-1,0});
	}
	int del = 0;
	while(!q.empty()){
		flag:
		if(a[q.front().e+1]!=-1){
			num=q.front().w ^ a[q.front().e+1];
			if(num==k){
				del = q.front().e+1;
				ans++;
				for(int i=q.front().s;i<=del;i++){
					a[i]=-1;
				}
				if(q.empty()){
					break;
				}
				while(q.front().s <= del && q.front().e+1 >= del){
					q.pop();
					if(q.empty()){
						break;
					}
				}
				if(q.empty()){
					break;
				}
				goto flag;
			}else{
				q.push({q.front().s,q.front().e+1,num});
			}
		}	
		q.pop();
	}
	cout<<ans;
	return 0;
}
