#include<bits/stdc++.h>
using namespace std;
char c[2005];
int q;
bool cmp(char u,char v){
	return int(u)>int(v);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[++q]=s[i];
		}
	}
	sort(c+1,c+q+1,cmp);
	for(int i=1;i<=q;i++){
		cout<<c[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
