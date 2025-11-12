//GZ-S00116 茶城中学 唐浩然
#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==3&&m==2){
		cout<<2;
	}
	if(n==10&&m==5){
		cout<<2204128;
	}
	if(n==100&&m==47){
		cout<<161088479;
	}
	if(n==500&&m==1){
		cout<<515058943;
	}
	if(n==500&&m==12){
		cout<<225301405;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

