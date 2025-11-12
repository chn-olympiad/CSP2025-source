#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+1;
string s;
int a[N],cnt=0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1){
		if(s[0]>='0'&&s[0]<='9'){
			cout<<s[0];
		}
	}else if(s.size()==2){
		if(s[0]==0&&s[1]==0){
			cout<<0;
		}else if(s[0]>='0'&&s[0]<='9'&&s[1]>='0'&&s[1]<='9'){
			if(s[0]>=s[1]){
				cout<<s[0]<<s[1];
			}else if(s[0]<s[1]){
				cout<<s[1]<<s[0];
			}
		}else if(s[0]>='0'&&s[0]<='9'&&s[1]>='a'&&s[1]<='z'){
			cout<<s[0];
		}else if(s[1]>='0'&&s[1]<='9'&&s[0]>='a'&&s[0]<='z'){
			cout<<s[1];
		}
	}else{
		for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
				cnt++;
				a[cnt]=(int)(s[i]-'0');
			}
		}
		sort(a+1,a+1+cnt,greater<int>());
		for(int i=1;i<=cnt;i++){
			cout<<a[i];
		}
	}
	return 0;
}