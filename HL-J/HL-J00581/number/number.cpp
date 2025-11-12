#include<bits/stdc++.h>
using namespace std;
long long a[10001];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    int sum=0;
    for(int i=0;i<n;i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		a[i]=s[i]-'0';
    		sum++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
	return 0;
}
