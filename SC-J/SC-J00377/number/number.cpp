#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
const int N=1e7+10;
int ax[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ax[++cnt]=s[i]-'0';
		}
	}	
	sort(ax+1,ax+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<ax[i];
	}
	return 0;
}