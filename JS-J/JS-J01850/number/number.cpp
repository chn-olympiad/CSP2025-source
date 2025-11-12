#include<bits/stdc++.h>
using namespace std;
string a;
int s[1000002];
int q=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=a.length();
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			q++;
			s[q]=a[i]-'0';
		}
	}
	std::sort(s+1,s+q+1);
	for(int i=q;i>=1;i--){
		cout<<s[i];
	}
	return 0;
}
