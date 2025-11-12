#include<bits/stdc++.h>
using namespace std;
string w;
int a[1000005],q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>w;
	for(int i=0;i<w.size();i++){
		if(int(w[i])-48>=0&&int(w[i])-48<=9) a[++q]=int(w[i])-48;
	}
	sort(a+1,a+q+1);
	for(int i=q;i>=1;i--) cout<<a[i];
	return 0;
}
