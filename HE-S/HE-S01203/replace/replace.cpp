#include <bits/stdc++.h>
using namespace std;

int n,q;
const int N=2e5+10;
string sf[N],sc[N],tf[N],tc[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%s %s",sf[i],sc[i]);
	for(int i=1;i<=q;i++) scanf("%s %s",tf[i],tc[i]);
	for(int i=1;i<=n;i++) printf("%s %s",sf[i],sc[i]);
	for(int i=1;i<=q;i++) printf("%s %s",tf[i],tc[i]);
	return 0;
}

