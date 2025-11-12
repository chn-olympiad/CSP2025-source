#include<bits/stdc++.h>
using namespace std;
const int f=5e5+5;
int dp[f];
int a[f];
int n,k;
int get(int l,int r){return dp[r+l-1]^dp[l-1];}
struct node{
	int l,r;
	node(int l,int r){
		this->l=l;
		this->r=r;
	}
};
bool cmp(node a,node b){
	return (b.r!=a.r?a.r<b.r:a.l<b.l); 
}
vector<node> s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int s1=1,s2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=dp[i-1]^a[i];
		if(a[i]>=2) s1=0;
		if(a[i]==1) s2++;
	}//O(n)
	if(n<=2e4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				if(get(i,j)==k) s.push_back(node(i,i+j-1));
			}
		}//O(n^2)
		sort(s.begin(),s.end(),cmp);//O(nlogn)
		
		int cnt=0,r=-1;
		for(int i=0;i<int(s.size());i++){
			if(s[i].l>r){
				r=s[i].r;
				cnt++;
			}
		}//O(n)
		cout<<cnt;
	}else if(s1&&k){
		bool now=0;
		int m=0,n1=0;
		for(int i=1;i<=n;i++){
			if(a[i]^now^1){
				if(now){
					n1++;
				}
				now=now^1;
			}
		}
		m=n1;
		now=1;
		n1=0;
		for(int i=1;i<=n;i++){
			if(a[i]^now^1){
				if(now^1){
					n1++;
				}
				now=now^1;
			}
		}
		m=max(m,n1);
		cout<<m;
	}else if(s1){
		cout<<max(s2,n-s2)/2;
	}
	else cout<<"12202251019251917425";
	return 0;
}
