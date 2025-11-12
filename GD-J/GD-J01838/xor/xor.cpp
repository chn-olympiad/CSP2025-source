#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1; 
int n,k,ans;
int s[N],sum[N]={};
struct st{
	int x,y;
};
vector<st> p;
bool cmp(st x,st y){
	return x.y<y.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		sum[i]=sum[i-1]^s[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				p.push_back({i,j});
			}
		}
	}
	sort(p.begin(),p.end(),cmp);
	int k=0;
	for(auto o:p){
		if(o.x>k){
			k=o.y;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}


