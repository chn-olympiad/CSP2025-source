#include<bits/stdc++.h>
using namespace std;

string s;
int a[20],cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lens=s.size();
	for(int i=0;i<lens;i++){
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++,cnt++;
	}
	if(cnt==a[0])printf("0");
	else{
		for(int i=9;i>=0;i--){
			for(int j=1;j<=a[i];j++){
				printf("%d",i);
			}
		}
	}
	return 0;
}
