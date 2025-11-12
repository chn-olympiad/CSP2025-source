//xor
#include<bits/stdc++.h>
using namespace std;
int n,k,a,cnt,t;
set<int> s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	s.insert(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		t^=a;
		if(s.count(k^t)){
			s.clear();
			t=0,cnt++;
		}
		s.insert(t);
	}
	printf("%d",cnt);
	return 0;
}
