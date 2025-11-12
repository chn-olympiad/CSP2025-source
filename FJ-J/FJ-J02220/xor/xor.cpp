#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e7+10;
int n,k,a[N];
struct node{
	int s,e;
}nd[M];
int c=0;
bool cmp(node x,node y){
	return x.s<y.s;
}
string f10_2(int x){
	string s,ss;
	int i=0,j=0;
	while(1){
		s[i]=(x%2==1?'1':'0');
		x/=2;i++;
		if(x==0){
			s[i]='1';
			break;	
		}
	}
	for(int q=i;q>=1;q--) ss[j++]=s[q];
	return ss;
}
string solve(string x,string y){
	int lx=x.size(),ly=y.size();
	string s;
	if(lx>ly)
		for(int i=1;i<=lx-ly;i++) y='0'+y;
	else if(ly>lx) 
		for(int i=1;i<=ly-lx;i++) x='0'+x;
	for(int i=0;i<max(lx,ly);i++){
		if(x[i]==y[i]) s[i]='1';
		else s[i]='0';
	}
	return s;
}
int f2_10(string s){
	int len=s.size(),ans=0,t=0;
	for(int i=len-1;i>=0;i--){
		if(s[i]=='1') ans+=(pow(2,t));
		t++; 
	}
	return ans;
}
void dfs(int l,int r){
	if(r>n) return;
	string ans;
	for(int i=l;i<r;i++){
		if(i==l) ans=f10_2(a[i]);
		else ans=solve(f10_2(a[i]),ans);
	}
	if(f2_10(ans)==k){
		nd[c].s=l,nd[c].e=r;
		c++;
	}
	dfs(l,r+1);
	dfs(l+1,r);
	if(l>r) return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	if(n<=2&&k==0) return cout<<0,0;
	else{
		dfs(0,0);
		sort(nd,nd+c,cmp);
		int ans=0;
		for(int i=0;i<c;i++){
			if(i==0) ans=1;
			else if((nd[i].s==nd[i-1].s)||((nd[i].s>nd[i-1].s)&&(nd[i].s<nd[i-1].e)))
				continue;
			else ans++;
		}
	cout<<ans;
	}
	
	return 0;
}
