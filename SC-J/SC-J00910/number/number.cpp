#include<bits/stdc++.h>
using namespace std;
const long long N=1E6;
char s[N+10];
long long cnt[20]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=strlen(s);
	for(int i=0;i<=n;i++){
		int cmp=s[i]-'0';
		if(cmp>=0&&cmp<=9) cnt[cmp]++;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]>0){
			cnt[i]--;
			cout<<i;
		}
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}