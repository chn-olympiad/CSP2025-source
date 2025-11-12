#include<bits/stdc++.h>
using namespace std;
string s;
const int maxn=1e6+10;
int num[maxn];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[cnt++]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt,cmp);
	if(num[1]==0){
		cout<<0<<'\n';
		return 0;
	}
	for(int i=1;i<cnt;i++){
		cout<<num[i];
	}
	return 0;
} 
