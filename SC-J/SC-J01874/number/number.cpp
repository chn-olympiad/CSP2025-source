#include<bits/stdc++.h>
using namespace std;
#define int long long
int b=-1,c,d;
char a;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> aa;
	while(cin>>a){
		if(a>='0'&&a<='9'){
			b++;
			aa.push_back(a-'0');
		}
	}
	sort(aa.begin(),aa.end());
	for(int i=b;i>=0;i--) cout<<aa[i];
	return 0;
	fclose(stdin);
	fclose(stdout);
}