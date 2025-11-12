#include<bits/stdc++.h>

using namespace std;
long long a[500005];
long long n,k;
long long pre[500005];
struct node{
	long long l,r;
};
long long cnt=0;
vector <node> fflag;
bool cmp(node a,node b){
	if(a.r!=b.r){
		return a.r<b.r;
	}
	return a.l<b.l;
}
long long solve1(){
	sort(fflag.begin(),fflag.end(),cmp);
	long long pos=0;
	long long ans=0;
	for(auto it:fflag){
		if(it.l>pos){
			ans++;
			pos=it.r;
		}
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((pre[j]^pre[i-1])==k){
					//cout<<i<<" "<<j<<endl;
					fflag.push_back({i,j});
					cnt++;
				}
			}
		}
		cout<<solve1();
		return 0;
	}else{
		int aans=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					aans++;
				}
			}
			cout<<aans;
			return 0;
		}
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					aans++;
				}
			}
			cout<<aans;
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((pre[j]^pre[i-1])==k){
					//cout<<i<<" "<<j<<endl;
					fflag.push_back({i,j});
					cnt++;
				}
			}
		}
		cout<<solve1();
	}
	
	return 0;
}
//65pts
