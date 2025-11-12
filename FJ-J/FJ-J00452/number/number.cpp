#include<bits/stdc++.h>
using namespace std;
long long ma[105],a,b,c,n,m,sum,ans;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
		ma[int(s[i])-int('0')]++;
	} 
	for(int i=9;i>=0;i--){
		while(ma[i]>0){
			ma[i]--;
			cout<<i;
		}
	}
	return 0;
}
