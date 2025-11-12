#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;
string s;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='0'&&s[i]>='9'){
			continue;
		}else{
			sum++;
			a[i]+=(s[i]-='0');
		}
	}
	sort(a+0,a+0+sum,cmp);
	for(int i=0;i<sum;i++){
		if(a[i]<=9&&a[i]>=0){
			cout<<a[i];
		}
	}
	return 0;
}
