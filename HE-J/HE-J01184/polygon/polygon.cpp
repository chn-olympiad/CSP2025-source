#include<bits/stdc++.h>
using namespace std;
long long q[5010],n,da,ls1,ls2,ls3,ls4;
int qwe(long long sd,long long maxx,long long xb,long long zh){
	if(zh>maxx*2&&sd>=2){
		da+=1;
		da=da%998244353;
	}
	for(int i=xb;i<n;i++){
		ls1=sd+1;
		ls2=max(maxx,q[i]);
		ls3=i+1;
		ls4=zh+q[i];
		qwe(ls1,ls2,ls3,ls4);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	qwe(0,-1,0,0);
	cout<<da;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

