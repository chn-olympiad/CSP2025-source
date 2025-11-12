#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int n=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n=n+1;
			a[n]=int(s[i])-48;
		}                                                        
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
