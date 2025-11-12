#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int cnt;
	string s;
	cin>>s;
	int l=s.length();
	string a;
	
	for(int i=0;i<=l;i++){
		if(int(s[i])>=96 && int(s[i])<=122){
			continue;
		}else{
			a[cnt]=s[i];
			cnt++;
		}
	}
	
	char b[cnt-1];
	for(int i=0;i<=cnt;i++){
		b[i]=a[i];
	}
	
	sort(b,b+cnt+1);
	for(int i=cnt;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
