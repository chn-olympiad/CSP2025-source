#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int num[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--)cout<<num[i];
	return 0;
}
//R;
