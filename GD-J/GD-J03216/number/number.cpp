#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int len,x[10],sx;
char s[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') x[s[i]-'0']++;
	}
	int sum=0;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=x[i];j++) cout<<i;
//		cout<<x[i]<<" ";
//		sum+=x[i];
	}
	return 0;
}
