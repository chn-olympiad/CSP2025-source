#include<bits/stdc++.h>
using namespace std;
int num=0, a[1000001];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num++;
			a[num]=s[i]-'0';
		}
	}
	sort(a+1,a+1+num);
	if(a[num]==0&&a[num-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=num;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

