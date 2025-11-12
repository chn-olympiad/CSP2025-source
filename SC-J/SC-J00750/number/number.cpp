#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size(),cnt=1;
	for(int i=0;i<n;++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i]-'0';
		}
	}
	--cnt;
	sort(a+1,a+1+cnt);
	if(a[cnt]==0){
		printf("0");
	}
	else{
		for(int i=cnt;i>=1;--i){
			printf("%d",a[i]);
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
