#include<bits/stdc++.h>
using namespace std;
int a[5005];
int s[5005];
int q[5005];
int bok[5005];
long long ans=0;
int n;
int cnt=0;
void dfs(int k,int step,int bef){
	int maxn=0;
	if(step==k){
		for(int i=0;i<k;i++){
			maxn=max(maxn,s[i]);
		}if(cnt>maxn*2){
			ans++;
		}return ;
	}for(int i=1;i<=n;i++){
		if(bok[i]==1 || i<=bef){
			continue;
		}bok[i]=1;
		s[step]=a[i];
		cnt+=a[i];
		dfs(k,step+1,i);
		cnt-=a[i];
		bok[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}if(maxn==1){
		int ans=0;
		for(int i=n-2;i>=1;i++){
			ans+=i*(i+1)/2;
			ans%=998244353;
		}cout<<ans;
		return 0;
	}
	for(int len=3;len<=n;len++){
		memset(bok,0,sizeof(bok));
		/*
		memset(q,0,sizeof(q));
		int h=1,t=1;
		q[t++]=a[1];
		for(int i=2;i<=len;i++){
			int g=q[t-1];
			while(h<t && a[g]<a[i]){
				t--;
			}q[t++]=i;
		}for(int l=1;l<=n-len+1;l++){
			int r=l+len-1;
			while(h<t && a[q[t-1]]<a[r]){
				t--;
			}q[t++]=r;
			if(t-h-1==len){
				h++;
			}
			if(s[r]-s[l-1]<=2*a[q[h]]){
				continue;
			}
			ans++;
			cout<<len<<' '<<l<<endl;
			ans=ans%998244353;
		}*/
		dfs(len,0,0);
	}cout<<ans;
	return 0;
}
