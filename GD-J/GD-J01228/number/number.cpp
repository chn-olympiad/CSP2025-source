#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
string a;
int num[maxn];
int q=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9') num[++q]=int(a[i]-'0');
	}
	sort(num+1,num+q+1);
	for(int i=q;i>=1;i--) cout<<num[i];
	return 0;
}//8.44
