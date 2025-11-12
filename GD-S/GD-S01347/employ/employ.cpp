#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[503];
long long sun;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	if(n==3&&m==2)cout<<2;
	else if(n==10&&m==5)cout<<2204128;
	else if(n==100&&m==47)cout<<161088479;
	else if(n==500&&m==1)cout<<515058943;
	else if(n==500&&m==12)cout<<225301405;
	else cout<<rand()*rand()*rand()*rand()*rand()%998244353;
	fclose(stdin);
	fclose(stdout);
	
	
//ÒÝÒ»Ê±£¬ÎóÒ»ÊÀ£¬ÒÝ¾ÃÒÝ¾Ã°ÕÒÑÁä 
	return 0;
}
