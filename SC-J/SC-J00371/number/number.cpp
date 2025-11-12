#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int ch[str.size()];
	int j=0;
	for(int i=0;i<int(str.size());i++){
		if(str[i]>='0' && str[i]<='9'){
			ch[j]=str[i]-'0';
			j++;
		}
	}
	sort(ch,ch+j,cmp);
	for(int i=0;i<j;i++){
		cout<<ch[i];
	}
	return 0;
}