#include<bits/stdc++.h> 
using namespace std;
long long a[1000006];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long sum=0;
	int f=0;
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			sum++;
			a[i]=s[i]-'0';
		}
		else continue;
	}
	sort(a,a+s.size(),cmp);
	for(long long i=0;i<s.size();i++){
		if(a[i]==0){
			continue;
		}
		else {
			f=1;
			break;
		}
	}
	if(f==1){
		for(long long i=0;i<sum;i++){
			cout<<a[i];
		}
	}
	else cout<<"0";
	return 0;
}
