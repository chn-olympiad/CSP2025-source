#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int n,k;
int ans;
int a[N];
bool ck[N];
vector<int> t[N];

struct node{
	int l,r,len;
};
vector<node> f;
bool cmp(node x,node y){
	if(x.len!=y.len)return x.len>y.len;
	if(x.l!=y.l)return x.l>y.l;
	return x.r>y.r;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n+1;i++){
		t[i].push_back(0);
	}t[n+1].push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i].push_back(a[i]);
		if(a[i]==k){
			f.push_back({i,i,1});
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int x=t[j][i-1]^t[j+1][i-1]^t[j+1][i-2];
			t[j].push_back(x);
			if(x==k){
				f.push_back({j,i+j-1,i});
			}
		}
	}
	sort(f.begin(),f.end(),cmp);
	while(f.size()){
		node p=f.back();
		f.pop_back();
		bool q=0;
		for(int i=p.l;i<=p.r;i++){
			if(ck[i]){
				q=1;
				break;
			}
		}if(q)continue;
		for(int i=p.l;i<=p.r;i++){
			ck[i]=1;
		}
		ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}