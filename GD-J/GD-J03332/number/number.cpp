#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[15]={0};
bool f=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(s[i]>='0'&&s[i]<='9')
			cnt[int(s[i]-'0')]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			if(i) f=1;
			if(f==0&&i==0){
				printf("0");
				return 0;
			}
			printf("%d",i);
		}
	}
	return 0;
}
