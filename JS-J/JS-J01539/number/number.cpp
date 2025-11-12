#include<bits/stdc++.h>
using namespace std;
int a[1000005],q=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int p=s.size();
	for(int i=0;i<p;i++){
		if(s[i]>=48&&s[i]<=57){
			a[q]=s[i]-48;
			q++;
		}
		}
	sort(a+1,a+q+1);
	for(int i=q;i>1;i--)cout<<a[i];
	return 0;
}
