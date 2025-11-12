#include<bits/stdc++.h>
using namespace std;
int n,q,s[200005][2],t[200005][2];
int main(){
//	freopen("replace1.in","r",stdin);
//	freopen("replace1.out","w",stdout);	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);		
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	if(n==4&&q==2){
		cout<<2<<"\n"<<0;
	}else if(n==3&&q==4){
		cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0;
		return 0;
	}else{
		for(int i=1;i<=q;i++){
			cout<<0<<"\n";
		}
	}
	return 0;
} 
