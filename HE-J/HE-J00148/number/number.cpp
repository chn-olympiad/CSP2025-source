#include<bits/stdc++.h>
using namespace std;
long long a[1005],ia=1;
string s;
bool f[1005];
int main(){
	memset(f,0,sizeof(f));
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		char ss=s[i];
		if(int(ss)>=48&&int(ss)<=57){
			a[ia]=int(ss)-48;
			ia++;
		}
	}
	sort(a,a+ia);
	for(int i=ia-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
