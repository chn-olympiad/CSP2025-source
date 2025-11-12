#include<bits/stdc++.h>
using namespace std;
int n,k;
int is=0;
int ns;
unordered_map<int,bool>mp;
int s=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&ns);
		is^=ns;
		if((k^is)==0||mp[k^is]==1){
			s++;
			is=0;
			mp.clear();
		}else mp[is]=1;
	}printf("%d",s);
	return 0;
}
