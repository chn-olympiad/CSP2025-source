#include<bits/stdc++.h>
using namespace std;
int a[500010]={};
int s[500010]={};
struct Re{
	int l,r;
};
bool cmp(Re x,Re y){
	return(x.r<y.r);
}
vector<Re>re;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^s[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[i-1]^s[j])==k){
				re.push_back({i,j});
			}
		}
	}
	sort(re.begin(),re.end(),cmp);
	int cnt=0;
	Re last={0,0};
	for(int i=0;i<re.size();i++){
		if(re[i].l>last.r){
			last=re[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
