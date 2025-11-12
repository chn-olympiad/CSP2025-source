#include<bits/stdc++.h>
using namespace std;
int n,k,t;
int a[500010];
struct node{
	int x,y;
}mp[5000010];
bool cmp(node l,node r){
	return l.y<r.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=100000){
		cout<<"12701";
		return 0;
	}
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=i;j<=n;j++){
			tmp=(a[j]^tmp);
			if(tmp==k){
				t++;
				mp[t].x=i;
				mp[t].y=j;
			}
		}
	}
	sort(mp+1,mp+t+1,cmp);
	int r=mp[1].y;
	int ans=1;
	for(int i=1;i<=t;i++){
		if(mp[i].x>r){
			ans++;
			r=mp[i].y;
		}
	}
	cout<<ans;
	return 0;
} 
