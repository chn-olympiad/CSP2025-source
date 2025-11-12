#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string str;
int c[N];
int cnt=1;
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>str;
	n=str.size();
	for(int i=0;i<n;i++){
		if(str[i]>='0' && str[i]<='9'){
			c[cnt]=str[i]-'0';
			cnt++;
		}
	} 
	sort(c+1,c+cnt);
	for(int i=cnt-1;i>=1;i--) cout<<c[i];
	return 0;
}
