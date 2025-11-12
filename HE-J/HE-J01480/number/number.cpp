#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int xx=0;
	for(int i=0;i<len;i++){
		if (s[i]>='0' and s[i]<='9'){
			xx++;
			a[xx]=s[i]-'0';
		}
	}
	sort(a+1,a+1+xx,cmp);
	for(int i=1;i<=xx;i++)cout<<a[i];
	return 0; 
} 
