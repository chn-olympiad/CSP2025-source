#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int q=1;
	for(int i=1;i<=s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[q]=s[i];
			q++;
		}
	}
	sort(a+1,a+q);
	for(int i=q;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
