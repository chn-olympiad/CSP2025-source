#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n,q;
string s[N][2];
string from,to;
int siz[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++){
		cin>>s[i][1]>>s[i][2];
		siz[i] = s[i][1].size();
	}
	while(q--){
		cin>>from>>to;
		if(from.size() != to.size()) printf("0\n");
		else{
			int ans = 0,id;
			for(int i = 1;i <= n;i++){
				id = from.find(s[i][1]);
				if(id != -1){
					if(from.substr(0,id) + s[i][2] + from.substr(id + siz[i]) == to) ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

