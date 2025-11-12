#include <bits/stdc++.h>
using namespace std;
char s[1000007];
int s1[1000007];
int n,h=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++){
		if((s[i]-'0'>9)||(s[i]-'0'<0)){
			continue;
		}
		else{
			s1[h]=s[i]-'0';
			h++;
		}
	}
	h--;
	sort(s1+1,s1+h+1);
	if(s1[h]==0){
		printf("0");
	}
	else{
		for(int i=h;i>=1;i--){
		printf("%d",s1[i]);
		
		}
	}
	
	
	return 0;
}
