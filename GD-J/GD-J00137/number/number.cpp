#include<iostream> 
using namespace std;
const int MAXN=1e2+5;
string s;
int cnt[MAXN],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0' && s[i]<='9') cnt[s[i]-'0']++;
	}
	bool flag=0;
	for(int i=9;i>=0;i--){
		if(!cnt[i]) continue;
		if(i!=0) flag=1;
		if(i==0 && !flag){
			cout<<0;
			return 0;
		}
		while(cnt[i]--) cout<<i;
	}
	return 0;
}
