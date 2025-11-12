#include<bits/stdc++.h>
using namespace std;
string s;
int n,t;
int a[1000001];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	printf("%s",s);
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++t]=s[i]-'0';
		}
	} 
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

	
