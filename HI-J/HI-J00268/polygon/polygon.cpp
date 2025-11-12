#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
	int a,b[10005],cnt=0;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	for(int i=1;i<=a;i++)
{	if(a>=3&&b[1]+b[a]>b[a]*2){
		cnt++;
	}
	else{
		cnt=0;
	}
}
	cout<<cnt;
	return 0;
}

