#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0),cout.tie(0);
	
	cin>>s;
	long long cnt=0;
	for(long long i=0;i<sizeof(s);i++){
		if(s[i]<='9' && s[i]>='0'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+0,a+0+cnt,cmp);
	for(long long i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}
