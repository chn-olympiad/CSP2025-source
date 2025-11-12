#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N];
bool cmp(int a,int b){
		return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long c=0;
	long long n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' and s[i]<='9'){
			c++;
		    a[i]=s[i]-'0';
			}sort(a,a+1+n,cmp);
		}for(int i=0;i<c;i++){
			cout<<a[i];
			}
	return 0;
}
