#include<bits/stdc++.h>
#define N 500001
using namespace std;
int n,k,a[N],flag=0;
int pre[N],ans=1,ansi;
inline int ch(int x,int y){
	if(x==y)return x;
	int anss,g,e1[21],e2[21];
	for(g=1;g<=21;g++){
		e1[g]=x%2,e2[g]=y%2;
		x/=2,y/=2;
		if(x==0&&y==0)break;
	}
	for(int k=1;k<=g;k++)
		if(e1[k]!=e2[k])
			anss+=2<<(k-2);
	return anss/2;
}
inline void dfs(int l){
	if(l==n)return;int kk=n-l+1;
	for(int si=1;si<=kk;si++){
		for(int ll=l;ll<=n-kk+1;ll++){
			int rr=ll+si-1;
			if(ch(pre[ll-1],pre[rr])==k){
				ansi++;dfs(rr+1);
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=ch(pre[i-1],a[i]);
		if(a[i]!=0||a[i]!=1)flag=1;
	}
	if(flag==0){
		int z=0,o=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)o++;
			else z++;
		}
		if(o==n){
			cout<<n;
			return 0;
		}
		if(k==1){
			cout<<o;
			return 0;
		}
		if(k==0){
			int an=z;
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i-1]==1){
					an++,i++;
				}
			}
			cout<<an;
			return 0;
		}
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			if(ch(pre[i-1],pre[j])==k){
				ansi=1;dfs(j+1);
				ans=max(ans,ansi);
			}
		}
	}
	cout<<ans;
	return 0;
}

