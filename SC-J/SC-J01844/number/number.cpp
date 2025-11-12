#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[j]=s[i]-48;
			cnt++;j++;
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<a[i];
	return 0;
}