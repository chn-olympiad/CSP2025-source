#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,ans=0,sum=0;
	set<int>s;
	scanf("%d%d",&n,&m);
	s.insert(0);
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		sum^=x;
		if(s.count(sum^m)){
			ans++;
			s.clear();
		}
		s.insert(sum);
	}
	printf("%d\n",ans);
	return 0;
}
