#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//ios::sync_with_stdio(0);
	srand(time(NULL));
	int x,T;
	cin>>x>>T;
	while(T--){
		int ans=rand()%1000;
		printf("%d\n",ans);
	}
	return 0;
}
