#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXX 1000005
using namespace std;

char s[MAXX],ans[MAXX],c;
int cnt=1;
bool cmp(int a,int b);

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lens=strlen(s);
	for(int i=0;i<lens;i++){
		char c=s[i];
		if(c>='0'&&c<='9'){
			ans[cnt]=c;
			cnt++;
		}
	}
	sort(ans+1,ans+cnt,cmp);;
	for(int i=1;i<cnt;i++){
		cout<<ans[i];
	}
	return 0;
}

bool cmp(int a,int b){
	return a>b;
}
