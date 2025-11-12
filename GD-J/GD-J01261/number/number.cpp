#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
char str[maxn]={};
int num[maxn]={};
int sum=0;
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<maxn;i++){
		if(str[i]<='9'&&str[i]>='0'){
			num[++sum]=str[i]-'0';
		}
	}
	sort(num+1,num+sum+1);
	for(int i=sum;i>=1;i--)cout<<num[i];
	return 0;
}
