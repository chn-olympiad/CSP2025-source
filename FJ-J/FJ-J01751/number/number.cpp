#include <bits/stdc++.h>
using namespace std;
int a[10000000];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int num=1;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[num]=s[i]-'0';
			num++;
		}
	}
    sort(a+1,a+1+num,cmp);
    for(int i=1;i<=num-1;i++){
    	cout<<a[i];
	}
}				
