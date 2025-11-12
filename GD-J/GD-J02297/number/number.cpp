//ccf orz
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f*=-1;
		c=getchar();
	}while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return f*x;
} 
string s;
int a[999],n;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(isdigit(s[i])){
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
