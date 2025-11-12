#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll A[5000005],ans,t;
bool cmp(int a,int b){return a>b;}
int char_int(char x){return int(x-'0'+0);}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	while((s[t]>='0'&&s[t]<='9')||(s[t]>='a'&&s[t]<='z')) t++;
	for(ll i=0;i<t;i++){
		if(s[i]>='0'&&s[i]<='9')
			A[++ans]=char_int(s[i]);
	}
	sort(A+1,A+ans+1,cmp);
	for(ll i=1;i<=ans;i++) cout<<A[i];
	return 0;
}