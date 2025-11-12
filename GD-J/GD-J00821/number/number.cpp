#include<bits/stdc++.h>
using namespace std;
char s[100001];
long long n,k,num,ans,a[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=sizeof(s);
	for(int i=0;i<n;i++){
		if(s[i]-48<=9&&s[i]-48>=0){
			a[i]=s[i]-48;
			num++;
		}
	}
	sort(a-num,a);
	for(int i=0;i<num;i++){
		cout<<a[i];
	}
	return 0;
}

