#include<bits/stdc++.h>
using namespace std;
char str[1000000];
long long num[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",str);
	long long cnt=0,b=strlen(str);
	for(long long i=0;i<b;i++){
		if(str[i]>='a' && str[i]<='z'){
			
		}
		else{
			if(str[i]>='0' && str[i]<='9'){
				num[i]=(int)str[i]-48;
			}
			else{
				break;
			}
		}
		cnt++;
	}
	sort(num,num+cnt);
	for(long long i=cnt-1;i>=0;i--){
		printf("%.lld",num[i]);
		if(num[i]==0){
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

