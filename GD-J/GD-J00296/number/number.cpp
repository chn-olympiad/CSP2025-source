#include<bits/stdc++.h>
using namespace std;
int n,cn;
int nu[10];
char a[1145141],ans[1145141];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&a);
	n=strlen(a);
	for(int i=0;i<n;i++){
		if(a[i]<='9'&&a[i]>='0'){
			nu[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<nu[i];j++){
			ans[cn]='0'+i;
			cn++;
		}
	}
	if(ans[0]=='0'){
		printf("0");
	}
	else{
		printf("%s",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
