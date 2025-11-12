#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long i2=0,cnt=0,w=1;
	string s;
	cin>>s;
	long long l=s.size();
	for(int i=0;i<l;i++){
		if(isdigit(s[i])){
			a[i2]=s[i]-'0';
			i2++;
			cnt++;
		}
	}
	sort(a,a+cnt,greater<int>());
	if(a[0]==0){
		cout<<0;
		return 0;
	}
	long long t=0;
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
} 
