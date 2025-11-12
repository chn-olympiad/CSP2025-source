#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+9;
int num[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin>>a;
	int c=1;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
			num[c]+=a[i]-'0';
			c++;
		}
	}
	
	sort(num+1,num+c);
	
	for(int i=c-1;i>=1;i--){
		cout<<num[i];
	}
	
	return 0;
}
