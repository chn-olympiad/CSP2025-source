#include<bits/stdc++.h>
using namespace std;
string s;
int n=1,m,k[10001],h=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=10001;i++)k[i]=-1;
	for(int i=0;(s[i]<='z'&&s[i]>='a')||(s[i]<='9'&&s[i]>='0');i++){
		if(s[i]<='9'&&s[i]>='0'){
			k[n]=s[i]-'0';
			n++;
		}
	}
	for(int i=1;k[i]!=-1;i++)h++;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=h-i;j++){
			if(k[j]<k[j+1]){
				m=k[j];
				k[j]=k[j+1];
				k[j+1]=m;
			}
		}
	}
	for(int i=1;i<=h-1;i++)cout<<k[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
