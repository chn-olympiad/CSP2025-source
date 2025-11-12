#include<bits/stdc++.h>
using namespace std;
string s,ans; 
char a[1000006];
long long j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++j]=s[i];
		}
	}
	sort(a,a+j+1);
	for(int i=j;i>=1;i--){
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}