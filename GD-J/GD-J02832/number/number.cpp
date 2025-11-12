#include<bits/stdc++.h>
#define ll long long
#define mn 1000001
using namespace std;
ll a[mn],i,step=1;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[step++]=s[i]-'0';
		}
	}
	step--;
	sort(a+1,a+step+1);
	for(i=step;i;i--){
		cout<<a[i];
	}
	return 0;
}
