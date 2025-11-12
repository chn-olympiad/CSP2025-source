#include<bits/stdc++.h>
using namespace std;
const int maxn=1000001;
char s[maxn];
char m[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int r=strlen(s);
	sort(s,s+r+1,cmp);
	for(int i=0;i<=r;i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			continue;
		}
		else{
			for(int j=i;j<=r;j++){
				s[j]=s[j+1];
			}
		}
	}
	int l=strlen(s);
	for(int i=0;i<=l;i++){
		m[i]=s[i];
	}
	int len=strlen(m);
	for(int i=0;i<len;i++){
		if(m[i]-'0'>=0 && m[i]-'0'<=9){
			cout<<m[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
