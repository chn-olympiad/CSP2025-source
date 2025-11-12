#include <bits/stdc++.h>
using namespace std;
string s;
int a[100010];
bool cmp(int a1,int b){
	return a1>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	int l=s.length();
	memset(a,-1,sizeof(a));
	if(l==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<l;i++) if(s[i]>='0'&&s[i]<='9') a[i]=s[i]-'0';
	sort(a,a+l,cmp);
	for(int i=0;i<l;i++) if(a[i]!=-1) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
