#include<bits/stdc++.h>
using namespace std;

const int N=1E6;
char s[N+10];
int cnt[20]={0};

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	int n=strlen(s);
	for(int i=0;i<n;i++){
		int tmp=s[i]-'0';
		if(tmp>=0&&tmp<=9)cnt[tmp]++;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]>0){
			cnt[i]--;
			printf("%d",i);
		}
	}
	
	fclose(stdin);fclose(stdout);
	return 0;

}
