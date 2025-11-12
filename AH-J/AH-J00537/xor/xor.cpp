#include<bits/stdc++.h>
using namespace std;
struct stu{
	int l,r;
}p[500100];
bool v[500101];
bool check(int l,int r){
	for(;l<=r;l++){
		if(v[l]==1)return 0;
	}
	return 1;
}
int n,k,a[510010],s[500101],cnt=0,l=1;
void dfs(int d,int ans){
	if(d>l-1)return;
	if(check(p[d].l,p[d].r)==1){
		for(int i=p[d].l;i<=p[d].r;i++){
			v[i]=1;
		}
		cnt=max(cnt,ans+1);
		dfs(d+1,ans+1);
		for(int i=p[d].l;i<=p[d].r;i++){
			v[i]=0;
		}
	}
	cnt=max(cnt,ans);
	dfs(d+1,ans);
	return;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]==k){
			p[l].l=1;p[l].r=i;
			l++;
		}
		for(int j=1;j<i;j++){
			int q=s[i]^s[j];
			if(q==k){
				p[l].l=j+1;p[l].r=i;
				l++;
			}
		}
	}
	dfs(1,0);
	cout<<cnt;
	return 0;
}
