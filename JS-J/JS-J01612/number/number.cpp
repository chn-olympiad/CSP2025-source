#include<bits/stdc++.h>
using namespace std;
int shu[1000001],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			shu[++cnt]=s[i]-'0';
		}
	}
	sort(shu+1,shu+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<shu[i];
    return 0;
}
