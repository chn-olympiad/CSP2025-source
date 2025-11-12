#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005];
int flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=s.size();
	for (int i=0;i<k;i++){
		if (s[i]>=48&&s[i]<=64){
			flag++;
			a[flag]=s[i]-'0';
		}
	}
	sort(a+1,a+1+flag);
	for (int i=flag;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
