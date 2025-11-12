#include <iostream>
using namespace std;
typedef long long LL;

char str[100010];
LL a[100010]={-1},len=1;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	char s;
	while(cin>>s){
		if(s>='0'&&s<='9'){
			a[len]=s-'0';
			len++;
		}
	}
	
	for(LL i=1;i<=len;i++){
		for(LL j=i;j<=len;j++){
			if(a[j]<=a[j+1]){
				LL q1=a[j];
				a[j]=a[j+1];
				a[j+1]=q1;
			}
		}
	}
	LL num=0,l=len;
	for(LL i=1;i<=len;i++){
		for(LL j=1;j<=l-1;j++){
			a[i]*=10;
		}num+=a[i];
		l--;
	}
	
	cout<<num<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
