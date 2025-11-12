#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long n,m,s,s1,b[N];
string a;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_sidio(0);
	cin.tie(0);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>=47&&a[i]<=57){
			b[i]=a[i]-'0';
		}
		else{
			s++;
		}
	}
	sort(b,b+n,cmp);
	for(int i=0;i<n-s;i++){
		cout<<b[i];
	}
	return 0;
} 