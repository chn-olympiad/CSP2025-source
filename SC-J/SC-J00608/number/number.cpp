#include<bits/stdc++.h>
using namespace std;
const int N=1e6+8;
string s;
int st[N],num[N];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int a=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++a]=(s[i]-'0');
		}else{
			st[i]=1;
		}
	}
	sort(num+1,num+a+1);
	for(int i=a;i>=1;i--){
		cout<<num[i];
	}
	return 0;
} 