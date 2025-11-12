#include<bits/stdc++.h>
using namespace std;
string s;
int a[300001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long tail=1;
	long long siz=s.size();
	for(int i=0;i<siz;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[tail]=s[i]-'0';
			tail++;
		}
	}
	sort(a+1,a+tail+1,cmp);
	for(int i=1;i<tail;i++){
		cout<<a[i];
	}
	return 0;
}
