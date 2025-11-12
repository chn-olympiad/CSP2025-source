#include <bits/stdc++.h>
using namespace std;
int a[1000010];
string s;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lenn=s.size(),cnt=0;
	for(int i=0;i<lenn;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i+1]=s[i]-'0';
			cnt++;
		}
	}
	int m=cnt;
	while(m--){
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<cnt;j++){
				if(a[i]<a[i+j]) swap(a[i],a[i+j]);
			}
		}
	}
	for(int i=1;i<=cnt;i++) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
}
