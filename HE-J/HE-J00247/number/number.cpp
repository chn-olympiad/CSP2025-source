#include<bits/stdc++.h>
using namespace std;
string s,ans;
int a[10]={'0','1','2','3','4','5','6','7','8','9'};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=10;i>=0;i--){
		for(int j=0;j<=len;j++){
			if(s[j]==a[i]){
				ans+=a[i];
			}
		}
	}
	for(int i=1;i<ans.size();i++){
		cout<<ans[i];
	}
	return 0;
}
