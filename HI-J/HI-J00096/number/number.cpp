#include<bits/stdc++.h>
using namespace std;
string s;int len,a[1000006];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			len++;
			a[len]=s[i]-'0'; 
		}
		
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++){
		printf("%d",a[i]);
	} 
	return 0;
} 
