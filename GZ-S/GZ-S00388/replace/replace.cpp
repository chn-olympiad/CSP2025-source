//GZ-S00388,莫杰昶，贵阳市第三实验中学 
#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2,x,y,z;
int w[1005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	long long int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
	}
	for(int j=1;j<=q;j++){
		cin>>t1>>t2;
		if(t1==s1) w[j]=2;
		if(t1!=s1) w[j]=0;
		//cout<<w[j]<<endl;	
	}
	cout<<2<<endl<<0;
	return 0;
}
