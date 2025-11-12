#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
char num[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0,l=s.length();
	for(int i=0;i<l;i++){
		if((s[i]>='0')&&(s[i]<='9')){
			cnt++;
			num[cnt]=s[i];
		}
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<num[i];
	}
	if(cnt==0) cout<<0;
	return 0;
}
