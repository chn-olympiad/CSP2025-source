#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt[15];
signed main(){
     freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     string str;
     cin>>str;
     for(int i=0;i<str.size();i++){
		 if(str[i]>='0'&&str[i]<='9'){
			 cnt[str[i]-'0']++;
	     }
	 }
	 for(int i=9;i>=0;i--){
		 for(int j=cnt[i];j>=1;j--){
			 cout<<i;
		 }
	 }
     return 0;
}
