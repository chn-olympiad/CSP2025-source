//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
char num[10000005];
long long a[10000005],cnt=1,sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;;++i){
		scanf("%c",&num[i]);
		if(isdigit(num[i])){
			a[cnt]=(num[i]-'0');
			cnt++;
			continue;
		}
		else if(num[i]=='\n'){
			cnt--;
			break;
		}
		else{
			continue;
		}
	}
	sort(a+1,a+cnt+1);
	for(long long i=cnt;i>=1;--i){
		cout<<a[i];
	}
	return 0;
}
