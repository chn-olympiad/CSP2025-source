#include <bits/stdc++.h>
using namespace std;

const int N=1000010;
string s;
int sum[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			sum[++cnt]=s[i]-'0';
		}
	}
	sort(sum+1,sum+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<sum[i];
	}
	return 0;
}
