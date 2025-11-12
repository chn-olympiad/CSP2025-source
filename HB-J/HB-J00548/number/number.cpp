#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int a[len]={0},ans=0;
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[ans++]=int(s[i])-48;
		}
	}
	sort(a,a+ans);
	for(int i=ans-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
