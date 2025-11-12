#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int a[10005],cnt=1,num=0;
bool cmp(int x,int y){
	return x>y;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='1' && s[i]<='9'){
			num++;
			a[cnt]=s[i]-'0';
			cnt++;
			
			}
		else if(s[i]=='0'){
			num++;
			a[cnt]=s[i]-'0';
			cnt++;
			}
			
		}
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		cout<<a[i];
		}
	return 0;
}
