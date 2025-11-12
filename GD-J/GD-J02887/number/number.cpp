#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
string s;
int c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=s.size();
	int b[a];
	for(int i=0;i<s.size();i++){
		if(s[i]<=57&&s[i]>=48){
			b[c]=s[i]-'0';
			c++;
		}
	}
	sort(b,b+a,cmp);
	for(int i=0;i<=c-1;i++){
		cout<<b[i];
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
