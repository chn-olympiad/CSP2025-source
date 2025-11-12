#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt;
string s;
bool flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
			if(a[cnt]>=1&&a[cnt]<=9) flag=1;
		} 
	}
	sort(a+1,a+cnt+1);
	if(flag){
		for(int i=cnt;i>=1;i--) cout<<a[i];
	}
	else cout<<0;
}
