#include<bits/stdc++.h>
using namespace std;
int a,t=1,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&q,&q);
	while(~scanf("%d",&a)){
		t*=a;
	}
	srand(t);
	while(q--) cout<<rand()<<endl;
	return 0;
}
