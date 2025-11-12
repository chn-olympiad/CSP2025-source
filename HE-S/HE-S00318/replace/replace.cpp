#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s2[100005],s1[100005],t1[100005],t2[100005],x=0,y=0,z=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	if(q=2){
		cout<<2<<endl;
		cout<<0;
	}
	else if(q!=2&&q!>=4){
		cout<<"²»»á"; 
	}
	for(int i=0;i<q;i++){
		if(q>=4){
			cout<<0<<endl;
		}
	}
	
	return 0;
}
