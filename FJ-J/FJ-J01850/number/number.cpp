#include<bits/stdc++.h>
using namespace std;
string s;
long long num[10000001];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	cin>>s;
	long long k=s.size();
	long long n=0;
	for(long long i=0;i<=k;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[n]=s[i]-'0';
			n++;
		}
	}
	sort(num,num+n,cmp);
	for(long long i=0;i<n;i++){
		cout<<num[i];
	}
	return 0;
} 
