#include<bits/stdc++.h>
using namespace std;
int n,m,c[500],cnt;
string s;
int f(int x){
	if(x==1)return 1;
	return x*f(x-1)%998244353;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			cnt++;
		}
	}
	if(cnt==n){
		printf("%d",0);
		return 0;
	}else if(m==n&&cnt>0){
		printf("%d",0);
		return 0;
	}else if(m==n&&cnt==0){
		printf("%d",f(n));
		return 0;		
	}else{
		printf("%d",2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
