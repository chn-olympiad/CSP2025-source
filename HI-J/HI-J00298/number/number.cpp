#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	string s;
	long long sum=0,cnt=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			if(a[i]!=0){
				cnt++;
			}
			sum++; 
		}
	}
	sort(a,a+s.size(),cmp);
	if(cnt==0){
		cout<<'0';
		return 0;
	}
	else{
		for(int i=0;i<sum;i++){
		cout<<a[i];
		}
	}
	return 0;
}

