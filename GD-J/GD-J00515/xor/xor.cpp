#include<bits/stdc++.h>
using namespace std;
int n,k,a[600020],f[600010];
int p[600010],b[2000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	f[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
		p[i]=0;
	}
	b[0]=0;
	p[0]=0;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1];
		if((f[i]^k)!=f[i]||f[i]==0)b[f[i]]=i;
		if(b[f[i]^k]==0&&(f[i]^k)!=0){
			continue;
		}
		p[i]=max(p[i-1],p[b[f[i]^k]]+1);
	}
	cout<<p[n];
	return 0;
}
//	int idx=0,ans=0;
//	for(int i=1;i<=n;i++){
////		cout<<i<<"!!!"<<idx<<endl;
//		for(int j=i-1;j>=idx;j--){
//			if(j==0){
//				if(f[i]==k){
//					idx=i;
//					ans++;
////					cout<<i<<" "<<j<<"\n";
//					break;
//				}
//			}else{
//				if((f[i]^f[j])==k){
//					idx=i;
//					ans++;
////					cout<<i<<" "<<j<<" "<<int(f[i]^f[j])<<"\n";
//					break;
//				}
//			}
//		}
//	}
//  cout<<ans;
