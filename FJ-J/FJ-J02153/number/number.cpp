#include <bits/stdc++.h>
#define int long long
using namespace std;
string s,ans;
int a[20],sum; 
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]<'a'||s[i]>'z'){//判断是否是数字 
			a[s[i]-'0']++; //桶中数字增加 
			sum++;//位数增加 
		}
	}
//	for(int i=9;i>=1;i--) {
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(int i=9;i>=0;i--) {
		if(a[i]>0){
			for(int j=1;j<=a[i];j++)
			ans+=char('0'+i);
		} 
	}
	cout<<ans;
	return 0;
}
