#include<bits/stdc++.h>
using namespace std;

string s;
const int N=1e6+5;
int a[N],cnt;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			cnt++;
			a[cnt]=(s[i]-'0');
		}
	}
	
	sort(a+1,a+1+cnt,cmp);
	
	for(int i=1;i<=cnt;i++) cout<<a[i];
	
	return 0;
}
