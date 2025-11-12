#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m=1;
long long num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[m++]=s[i]-'0';
		}
	}
	sort(num+1,num+m);
	for(int i=m-1;i>0;i--){
		cout<<num[i];
	}

	return 0;
}

