#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,cnt,maxn=-1;
long long a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	int TF=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) TF=0;
	}
	if(TF==1&&k==0){
		cout<<n/2;
	}else if(TF==1&&k==1){
		cout<<n;
	}else if(TF==0&&k==0){
		for(int i=1;i<=n;i++){
			ans=0,cnt=0;
			for(int j=i;j<=n;j++){
				ans+=a[j];
				if(ans==a[j+1]){
					cnt++,ans=0;
				}else if(a[j]==k){
					cnt++;
					ans=0;
				}
			}
			maxn=max(maxn,cnt);
		}
		cout<<maxn;
	}else{
		queue<int>q;
		queue<int>q2;
		q.push(a[1]);
		for(int i=2;i<=n;i++){
		if(!q.empty()){
			while(!q.empty()){
				int x=q.front();
				//cout<<"hehe "<<x<<endl;
				q.pop();
				q2.push(abs(x+a[i]));
				q2.push(abs(x-a[i]));
				if(abs(x+a[i])==k) ans++;
				if(abs(x-a[i])==k) ans++;
			}
		}else{
			while(!q2.empty()){
				int x=q2.front();
				//cout<<"hehe "<<x<<endl;
				q2.pop();
				q.push(abs(x+a[i]));
				q.push(abs(x-a[i]));
				if(abs(x+a[i])==k) ans++;
				if(abs(x-a[i])==k) ans++;
			}
		}
		}
		ans/=2;
		for(int i=1;i<=n;i++){
			if(a[i]==k) ans++;
		}
		cout<<ans;
	}
	return 0;
}
