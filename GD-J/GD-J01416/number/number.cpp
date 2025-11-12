#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],len;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++len]=s[i]-'0';
	}
	sort(a+1,a+1+len);
	bool isfst=1;
	for(int i=len;i>=1;i--){
		if(isfst==1){
			if(a[i]==0){
				if(i==1) cout<<a[i];
				continue;
			}
			cout<<a[i],isfst=0;
		}
		else cout<<a[i];
	}
	return 0;
} 
