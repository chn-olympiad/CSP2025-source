#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long ans;
long long a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	long long b;//wuyong
    long long f=1;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z'){
			b=1;
		}
		else{  
		a[f]=(s[i]-'0');
		f++;
		}
	}
   	sort(a+1,a+1+f);
	for(int i=f;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
