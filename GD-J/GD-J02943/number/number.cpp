#include<bits/stdc++.h>
using namespace std;
int ans,sum[1000002];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length(),k=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum[k]=s[i]-48;
			k++;
		}
	}
	sort(sum,sum+k);
	for(int i=k-1;i>=0;i--)cout<<sum[i];
	return 0;
}
