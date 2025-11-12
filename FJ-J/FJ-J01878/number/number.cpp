#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[10000];
	cin>>s;
	int t=s.size(),b=0;
	for(int i=0;i<t;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=s[i];
			b++;
		}
		else{
			break;
		}
	}
	sort(a,a+t);
	cout<<a;
	return 0;
}
