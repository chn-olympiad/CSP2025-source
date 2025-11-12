#include<bits/stdc++.h>
using namespace std;
string s1;
int a[1000005],cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	for(int i=0;i<s1.length();i++){
		if(s1[i]<='9' && s1[i]>='0'){
			cnt++;
			a[cnt]=s1[i]-48;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}       
