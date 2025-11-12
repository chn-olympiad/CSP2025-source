#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int num[N];
long long cnt=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[cnt]=s[i]-'0';
			cnt++;
		}	
	}
	cout<<cnt<<endl;
	sort(num,num+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
