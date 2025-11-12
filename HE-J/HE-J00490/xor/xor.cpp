#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> awa;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,a;i<=n;i++){
		scanf("%d",&a);
		awa.push_back(a);
	}
	int ans=0;
	int qwq=0;
	for(int i=0;i<awa.size();i++){
		qwq=qwq^awa[i];
		if(qwq==m){
			ans++;
			qwq=0;
		}
	}
	printf("%d",ans);
	return 0;
}
