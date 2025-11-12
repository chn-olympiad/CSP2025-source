#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long cnt=0,len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>=0&&s[i]<=9){
			cnt++;
			a[i]=s[i]-'0';
		}
	}
	sort(a,a+cnt);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}
