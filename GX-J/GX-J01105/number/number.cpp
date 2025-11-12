#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
freopen("number.in","r",in);
freopen("number.out","w",out);
int k=0,a[100005];
string s;
cin>>s;
int b=s.size();
for(int i=1;i<=b;i++){
	if(s[i]>='0'&&s[i]<='9'){
		k++;
		a[k]=s[i];
		}
	}
sort(a,a+1);
for(int i=k;k>=1;i--){
	cout<<a[i];
	}
return 0;
}
