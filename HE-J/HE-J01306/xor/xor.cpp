#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+1,V=(1<<21);
int n,k,a[N],s[N],ans,buc[V];
int main(){
	freopen("xor.in","r",stdin),
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1,pos;i<=n;){
		buc[s[i-1]]=1,pos=-1;
		for(int j=i;j<=n;j++){
			if(buc[s[j]^k]){
				pos=j;
				break;
			}
			buc[s[j]]=1;
		}
		if(pos==-1)
			break;
		for(int j=i-1;j<=pos+1;j++)
			buc[s[j]]=0;
		ans++,i=pos+1;
	}
	cout<<ans;
	return 0;
}
//Can I AK this? I hope so.
