#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000003];
bool d[1000003];
int cmp(char a,char b){
	if(a<'a' && b<'a'){
		return a>b;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<'a'){
			d[i]=true;
			a[i]=s[i];
			ans++;	
		}
	}
	sort(a,a+ans,cmp);
    for(int i=0;i<s.size();i++){
		if(a[i]){
			cout<<a[i];
		}
	}
	return 0;
}
