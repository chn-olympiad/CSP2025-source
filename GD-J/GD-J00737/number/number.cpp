#include<bits/stdc++.h> 
#define int long long
using namespace std;
inline int read(){
	char ch;
	int sum=0,x=1;
	ch=getchar();
	while(ch<'0'||(ch>'9')){
		if(ch=='-')x=-1;
		ch=getchar(); 
	}
	while((ch>='0')&&(ch<='9')){
		sum=(sum<<3)+(sum<<1)+(ch^48);
		ch=getchar();
	}
	return sum*x;
}
//zzzzzz
int a[10];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&(s[i]<='9')){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			printf("%lld",i);
		}
	}
	return 0;
}
