#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
long long k;
long long a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=s.size();
	for(long long i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			k+=1;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	if(a[k]==0){
		cout<<"0";
	}else{
		for(long long i=k;i>=1;i--){
		cout<<a[i];
		}
	}
return 0;
}
