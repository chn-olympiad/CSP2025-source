#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int pre[500005],lst,ans;
map<int,set<int> >s;//number position
set<int>::iterator it;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	s[0].insert(0);
	for(int i=1;i<=n;i++){
		int tmp=pre[i]^k;
		if(!s.count(tmp)){
			s[pre[i]].insert(i);
			continue;
		}
		it=s[tmp].end();
		it--;
		s[pre[i]].insert(i);
		if((*it)>=lst){
			lst=i;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
