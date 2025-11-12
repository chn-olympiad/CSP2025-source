#include<bits/stdc++.h>
using namespace std;
struct qj{
	int l,r;
};
vector<qj> q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	int a[500010]={0};
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			int l=i,r=j,sum=a[i];
			for(int k=i;k<=j;++k){
				sum=sum|a[j];
			}
			if(sum==k){
				q.push_back((qj){i,j});
				//++cnt;
			}
		}
	}
	for(int i=0;i<q.size();++i){
		for(int j=i+1;j<q.size();++j){
			qj a=q[i];
			for(int i=q[j].l;i<=q[j].r;++i){
				if(i>=a.l&&i<=a.r){
					q.erase(q.begin()+j);
				}
			}
		}
	}
	cout<<q.size();
	return 0; 
}