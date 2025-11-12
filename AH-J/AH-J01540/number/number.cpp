#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
string s;
int a[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long n=s.size();
    long long d=0;
    for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++d]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=d;i++){
		cout<<a[i];
	}
    return 0;
}

