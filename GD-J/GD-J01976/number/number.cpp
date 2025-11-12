#include<bits/stdc++.h>
#include<cstring>
using namespace std;
const int p=1000007;
char s[p];

int t[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<=p;i++){
		if(s[i]>='0'&&s[i]<='9'){
		cnt++;
		t[s[i]-'0']++;	
		} 
	}
	for(int i=9;i>=0;i--){
		while(t[i]>0){
			t[i]--;
			printf("%d",i);
		}
	}
	return 0;
}
