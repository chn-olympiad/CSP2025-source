#include<bits/stdc++.h>
using namespace std;
string s;
long long b[1000005],j;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			b[j]=s[i]-'0';
		}
	}
	sort(b+1,b+j+1,cmp);
	for(int k=1;k<=j;k++){
		cout<<b[k];
	}
	return 0;
}
