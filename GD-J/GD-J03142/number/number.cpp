#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
string s;
int arr[1000005],tot=0;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin>>s;
	for(int i=s.size()-1;i>=0;--i)
		if('0'<=s[i]&&s[i]<='9')
			arr[++tot]=s[i]-'0';
	sort(arr+1,arr+1+tot);
	for(int i=tot;i>0;--i)cout<<arr[i];
	
 return 0;
}
