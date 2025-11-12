#include<bits/stdc++.h>
using namespace std;
int v[1000001];
char s[1000001];
bool cmp(int &x,int &y){
	return x>y;
}
int k=1,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(isdigit(s[i])){
			v[n++]=s[i]-48;
		}
	}
	sort(v,v+n,cmp);
	for(int i=0;i<n;i++){
		if(k&&v[i]==0){
		}else{
			k=0;
			cout<<v[i];
			i++;
		}
	}
	if(k)cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
