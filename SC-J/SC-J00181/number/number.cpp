#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e6+10;
vector<int> num;
int cnt[10];
bool cmp(int a,int b){
	return a>b;
}
char s[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num.push_back(s[i]-'0');
		}
	}
	sort(num.begin(),num.end(),cmp);
	for(int k:num)cout<<k;
	
	return 0;
}