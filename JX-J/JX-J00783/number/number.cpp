#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	string s;
	int a[1000010];
	int l=1;
	cin>>s;
	int c=s.size();
	for(int i=0;i<c;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[l]=s[i]-'0';
			l++;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
