#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int a[MAXN];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int index_n=0,len_s=s.length();
	for(int i=0;i<len_s;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[index_n]=s[i]-'0';
			index_n++;
		}
	}
	sort(a,a+index_n,cmp);
	for(int i=0;i<index_n;i++){
		cout<<a[i];
	}
	return 0;
}
