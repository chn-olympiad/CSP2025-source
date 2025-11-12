#include<bits/stdc++.h>
using namespace std;
const int x=1e6+5;
char a[x];
bool cmp(char a,char b){
	if(a!=b) return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int sum=0;
    string s;cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		a[i]=s[i];
    		sum++;
		}
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<sum;i++)
		cout<<a[i];
return 0;
}

