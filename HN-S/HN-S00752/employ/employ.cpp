#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int o=0;
long long ans1=1;
long long ans2=1;
long long ans=1;
long long ans3=0;
int flag=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}	
	while(s[o]!='0' and o<s.size()){
		o++;
	}
	for(int i=n;i>1;i--){
		ans1=ans1*i;
	}
	for(int j=o;j>=2;j--){
		ans2=1;
	for(int h=2;h<=n-j;h++){
		ans2=ans2*h;	
	}
	//cout<<ans2<<endl;
	ans=ans1/ans2;
	ans3 =ans3+ans;
	}
	
	
	ans3=ans3%998%244%353;
	cout<<ans3;
	return 0;
	
}
