#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string s;
int ans[N],num,sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	num=s.size();
	for(int i=0;i<num;i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum++;
			ans[sum]=int(s[i])-48;
		}
	}
	sort(ans+1,ans+1+sum);
	for(int i=sum;i>=1;i--)
		cout<<ans[i];
	return 0;
}
