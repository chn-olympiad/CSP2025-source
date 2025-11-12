#include<bits/stdc++.h>
using namespace std;
long long a[100100],num;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i];
			num++;
		}
	}
	sort(a,a+num);
	for(int i=num-1;i>=0;i--){
		cout<<char(a[i]);
	}
	return 0;
}