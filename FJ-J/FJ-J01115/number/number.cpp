#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],ans;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			a[++ans]=s[i]-'0';
		}
	}
	sort(a+1,a+1+ans,cmp);
	for (int i=1;i<=ans;i++){
		printf("%d",a[i]);
	}
	return 0;	
}
