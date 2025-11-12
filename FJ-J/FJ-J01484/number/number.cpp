#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
int cnt;//记录0的个数 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++k]=s[i]-'0';
		}
	}
	
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
	return 0;
}
