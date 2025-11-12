#include<bits/stdc++.h>
using namespace std;
int t,a=0;
int lst[4];
int myd=0;
void club(int n){
	for(int i=1;i<=n;i++){
		cin>>lst[1]>>lst[2]>>lst[3];
		a=lst[1];
		if(lst[2]>a)a=lst[2];
		if(lst[3]>a)a=lst[3];
		myd+=a;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout)
	cin>>t;
	int num;
	for(int i=0;i<t;i++){
		cin>>num;
		club(num);
		cout<<myd<<endl;
		myd=0;
	}
	fclose(stdin);
	fclose(stdout);
} 
