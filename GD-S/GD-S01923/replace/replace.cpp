#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,q;
string s[N],t[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++)cin >> s[i]>>t[i];
	for(int i=1;i<=q;i++){
		cin >> t1 >> t2;
		int ans = 0;
		for(int j=1;j<=n;j++){
			int x = t1.find(s[j]),y = t2.find(t[j]);
			while(x!=y){
				if(x==-1||y==-1)break;
				if(x<y)x = t1.find(s[j],x+1);
				else y = t2.find(t[j],y+1);
			}if(x==-1)break;
//			cout << x << " "<< y<<endl;
			bool flag = 1;
			for(int k=0;k<x;k++)if(t1[k]!=t2[k])flag = 0;
			for(int k=x+s[j].size();k<t1.size();k++)if(t1[k]!=t2[k])flag = 0;
			if(flag)ans++;
		}cout << ans << endl;
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
