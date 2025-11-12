#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],f[500005],l,maxx[5000005];
vector<pair<int,int> > ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=(s[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				ans.push_back({i,j});
				l++;
			}
		}
	}
//	for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	f[1]=1,maxx[1]=ans[0].second;
//	for(int i=2;i<=l;i++){
//		f[i]=f[i-1],maxx[i]=maxx[i-1];
//		for(int j=i-1;j>=1;j--){
//			if(ans[i-1].first>maxx[j]){
//				f[i]=max(f[i],f[j]+1);
//				maxx[i]=ans[i-1].second;
//			}
//		}
//	}
	for(int i=2;i<=l;i++){
		for(int j=i-1;j>=1;j--){
			if(ans[i-1].first>maxx[j]){
				f[i]=max(f[i],f[j]+1);
				maxx[i]=ans[i-1].second;
			}
			else{
				if(f[j]>f[i]||(f[j]==f[i]&&maxx[j]<maxx[i])){
					f[i]=f[j];
					maxx[i]=maxx[j];
				}
			}
		}
	}
	cout<<f[l];
	return 0;
}

