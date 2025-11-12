#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
int num=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int S=s.size();
	for(int i=0;i<S;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num++;
			a[num]=s[i]-'0';
		}
	}
	sort(a+1,a+1+num,cmp);
	for(int i=1;i<=num;i++){
		cout<<a[i];
	}
	return 0;
}
