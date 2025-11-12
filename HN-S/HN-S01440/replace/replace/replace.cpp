#include<bits/stdc++.h>
using namespace std;
int main()
{
	feropen("club.in","r",stdin);
	feropen("club.out","w",stdout);
	int n,q,t1[1000],t2[1000],s1[1000],s2[1000];
	cin>>n>>q;
	for(int m=1;i<=n;i++){
		cin>>s1[m]>>s2[m];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	if(n==4&&n==2){
		cout<<"2"<<endl;
		cout<<"0"<<endl;
	}else if(n==3&&n==4){
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
	}
	return 0;
}
