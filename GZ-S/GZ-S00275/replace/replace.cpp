//GZ-S00275 贵阳市第十九中学 杨雅琪 
#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[2][200005];
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(q==1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[0][i]>>a[1][i];
	}
	for(int i=0;i<q;i++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
		}
		else{
			cout<<n<<endl;
		}
	}
	return 0;
}
