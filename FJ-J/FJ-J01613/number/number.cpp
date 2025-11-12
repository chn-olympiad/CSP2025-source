#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+9;
string s;
long long cnt,a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		char c=s[i];
		if(int(c)>=97&&int(c)<=122){
			continue;
		}
		else{
			cnt++;
			a[cnt]=s[i]-'0';
			
		}
	}
	//if(cnt==1){
	//	cout<<a[1];
//	}else {
		sort(a+1,a+1+cnt,greater<long long>());
		for(int i=1;i<=cnt;i++)cout<<a[i];
	//}
	return 0;
} 
