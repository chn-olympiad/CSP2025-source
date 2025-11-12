#include<bits/stdc++.h>
using namespace std;
string s,s1;
int a[1001000],ans=1;
int cmp(int a,int b){
	return a>b;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[ans]=s[i]-'0';
			ans++;
		}
	}
	sort(a+1,a+ans+1,cmp);
	for(int i=1;i<=ans-1;i++){
		printf("%d",a[i]);
	}
	return 0;
} 
