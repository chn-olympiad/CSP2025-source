# include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],idx=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++idx]=int(s[i]-'0');
		}
	}
	sort(a+1,a+idx+1,cmp);
	for(int i=1;i<=idx;i++) printf("%d",a[i]);
	return 0;
}