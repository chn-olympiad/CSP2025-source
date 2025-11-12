#include<bits/stdc++.h>
using namespace std;
long long a[10000001];
string s;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	long long ans=0;
	for(long long i=0;i<=len-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++ans]=s[i]-'0';
		}
	}
	sort(a+1,a+ans+1,cmp);
	for(long long i=1;i<=ans;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
