#include<bits/stdc++.h>
using namespace std;
char s[1000005],a;
int sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	if(n==1){
		cout<<s;
	}
	else{
		for(int i=0;i<=n;i++){
			if(s[i]>='0'&&s[i]<='9'){
				sum++;
			}
		}
		for(int j=1;j<=sum;j++){
			for(int i=0;i<=n;i++){
				if(s[i]>='0'&&s[i]<='9'){
					if(s[i]>a){
						a=s[i];
						s[i]='a';
					}
				}
			}
			cout<<a;
			a=0;
		}
		
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
