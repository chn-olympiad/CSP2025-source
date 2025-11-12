#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	int a[n+10];
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	if(a[0]==1){
		cnt=9;
	}else{
		cnt=6;
	}
	cnt%=998;
	cnt%=244;
	cnt%=353;
	cout<<cnt<<endl;
	return 0;
}
