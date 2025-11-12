#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],j=1,x=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(isdigit(s[i])){
			a[j]=(int)s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j);
	while(a[j]==0&&j>=1) --j;
	for(int i=j;i>=1;--i) printf("%d",a[i]);
	return 0;
}
