#include <bits/stdc++.h>
using namespace std;
int a[10000005]={0},n=1;
string s;
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[n]=s[i]-'0';
            n++;
        }
	}
	sort(a+1,a+n+1,cmp);
	if(a[1]==0){
        cout<<0;
        return 0;
	}
	for(int i=1;i<n;i++){
        cout<<a[i];
	}
	return 0;
}
