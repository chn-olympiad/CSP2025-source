#include<bits/stdc++.h>
using namespace std;
string s;
int t[15],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			t[s[i]-'0']++;
		}
	}
	string ts="";
	for(int i=9;i>=0;i--){
		if(cnt==0)break;
		if(t[i]){
			while(t[i]--){
				cnt--;
				ts+=char(i+'0');
			}
		}
	}
	while(ts.size()>1&&ts[0]=='0')ts.erase(0,1);
	cout<<ts;
}
