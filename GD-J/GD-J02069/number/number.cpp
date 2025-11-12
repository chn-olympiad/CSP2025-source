#include<bits/stdc++.h>
using namespace std;
int n,t,bz[14];
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]<'0'||s[i]>'9') continue;
		bz[s[i]-'0']++;
	}
	for(int i=9;i;i--){
		while(bz[i]) printf("%d",i),bz[i]--,t=1;
	}
	if(!t&&bz[0]) printf("0");
	else{
		while(bz[0]) printf("0"),bz[0]--;
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
