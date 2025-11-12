#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
string s;
int a[N],n,t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[t]=s[i]-'0';
			t+=1;
		}
	}
	sort(a+0,a+t);
	for(int i=t-1;i>=0;i--){
		std::cout<<a[i];
	}
	return 0;
}
