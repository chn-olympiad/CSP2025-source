#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010];
string str;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>str;
	int j=0;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			j++;
			a[j]=str[i]-'0';
		}
	}
	sort(a+1,a+1+j,cmp);
	for(int i=1;i<=j;i++){
		cout<<a[i];
	}
	return 0;
}
