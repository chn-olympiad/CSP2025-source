#include<bits/stdc++.h>
using namespace std;

string s;
long long num[1000006];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long cnt=0;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			num[cnt]=(s[i]-'0');
		}
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;++i){
		cout<<num[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
