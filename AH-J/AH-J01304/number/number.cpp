#include<bits/stdc++.h>
using namespace std;
long long c,len;
long long a[1000010];
string s;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    len=s.size();
    for(long long i=0;i<len;i++){
		if(isdigit(s[i])){
			a[++c]=s[i]-'0';
		}
	}
	sort(a+1,a+c+1,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	else{
		for(long long i=1;i<=c;i++){
			cout<<a[i];
		}
	}
}
