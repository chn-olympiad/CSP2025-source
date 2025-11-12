#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
long long a[1000010];
bool cmp(long long a,long long b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j,cmp);
	for(int i=1;i<j;i++){
		cout<<a[i];
	}
} 
