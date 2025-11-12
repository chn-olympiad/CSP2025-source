#include<bits/stdc++.h>
using namespace std;
#define N 1500005

string s;
int sum[N],cnt;

int cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=1;i<=len;i++){
		if(s[i-1]-'0'>=0&&s[i-1]-'0'<=9){
			sum[++cnt]=s[i-1]-'0';
		}
	}
	sort(sum+1,sum+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<sum[i];
	}
	return 0;
}