#include<bits/stdc++.h> 
using namespace std;
int a[1000005]={0};
bool cmp(int x,int y){
	if(x<=y)return 0;
	else return 1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long n,t,cnt=1;
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			n=s[i]-'0';
			a[cnt]=n;
			cnt++;
		}
	}sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}
