#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],len;
string s;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		char c;
		c=s[i];
		if(c>='0'&&c<='9') a[i]=c-'0',len++;
	}
	sort(a,a+s.size(),cmp);
	long long ans=0;
	for(int i=0;i<len;i++){
		ans*=10;
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
