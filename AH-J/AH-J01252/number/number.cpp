#include<bits/stdc++.h>
using namespace std;
long long cnt[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	cin>>s;
	for(long long i=0;i<(long long)s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt[s[i]-'0']++;
        }
	
	}
	for(int i=9;i>=0;i--){
        for(long long j=1;j<=cnt[i];j++){
            ans+=(i+'0');
        }
    }
	cout<<ans;
	return 0;

}
