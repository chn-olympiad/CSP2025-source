#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
int a[1000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int j=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			a[j]=int(s[i]-'0');
		}
	}
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<=j;i++){
		cout<<a[i];
	}
	return 0;
}
