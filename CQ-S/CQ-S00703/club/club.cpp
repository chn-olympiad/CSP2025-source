#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,maxn=0;
};
node door[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>door[i].a>>door[i].b>>door[i].c;
			door[i].maxn=max(door[i].a,max(door[i].b,door[i].c));
		}
		int maxn=0;
	    for(int i=1;i<=n;i++){
	    	maxn+=door[i].maxn;
		}
		cout<<maxn<<endl;
	}
	return 0;
} 
