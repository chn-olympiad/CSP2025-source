#include<bits/stdc++.h>
using namespace std;
long long a[1010000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long ans=1;
	long long l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ans]+=s[i]-'0';
			ans++;
		}
	}sort(a+1,a+1+ans);
	for(long long i=ans;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
