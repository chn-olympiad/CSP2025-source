#include<bits/stdc++.h>
using namespace std;
const int N=1e7+101;
string s;
long long a[N],k;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=s.length();
	for(long long i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k,cmp);
	for(long long i=1;i<=k;i++){
		if(i==1&&a[i]==0){
			cout<<0;
			return 0;
		}else{
			cout<<a[i];
		}
	}
	return 0;
} 
