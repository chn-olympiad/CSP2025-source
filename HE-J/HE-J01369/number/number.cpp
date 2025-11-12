#include<bits/stdc++.h>
using namespace std;
bool cmd(long long a,long long b){
	return a>b;
}
long long ans=0,a[1000005],un=1;
string s;
int main(){
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[un]=s[i]-'0';
			un++;
		}
	}
	sort(a+1,a+un,cmd);
	for(int i=1;i<un;i++)
		ans=ans*10+a[i];
	cout<<ans;
} //期望得分 100,O(n)
