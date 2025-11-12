#include<bits/stdc++.h>
using namespace std;
long long a[10000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;long long cnt=0;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(long long i=1;i<=cnt;i++){
		cout<<a[i];
		if(a[i]==0&&i==1) return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
