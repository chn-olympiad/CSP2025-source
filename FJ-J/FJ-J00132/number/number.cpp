#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++c]=s[i]-'0';
		}
	}
	sort(a+1,a+1+c,cmp);
	for(int i=1;i<=c;i++){
		std::cout<<a[i];
	}
	return 0;
}
