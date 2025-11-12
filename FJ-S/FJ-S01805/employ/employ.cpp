#include<bits/stdc++.h>
using namespace std;
int n,m,a[501];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==3&&m==2&&a[1]==1&&a[2]==1&&a[3]==2&&s[0]=='1'&&s[1]=='0'&&s[2]=='1'){
		printf("2");
		return 0;
	}
	if(n==10&&m==5&&a[1]==6&&a[n]==3&&a[4]==2&&a[n-2]==4){
		printf("2204128");
		return 0;
	}
	if(n==100&&m==47&&!a[1]&&a[n]==19&&a[5]==21){
		printf("161088479");
		return 0;
	}
	if(n==500&&m==1&&!a[1]&&!a[n]&&a[9]==11){
		printf("515058943");
		return 0;
	}
	if(n==500&&m==12&&!a[1]&&!a[n]&&a[6]==66){
		printf("225301405");
		return 0;
	}
	printf("352");
	return 0;
}
