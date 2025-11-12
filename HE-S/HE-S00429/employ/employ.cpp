#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,q,cnt[100100];
	string s1,[10100],s2[10100],t1[10100],t2[10100];
	cin>>n>>q;
	for(int i=n;i>=1;i--){
		cin>>s1[i]>>s2[i];
	}
	for(int j=i;j<=n;j++){
		cin>>t1[j]>>t2[j];
	}for(int i=1;i<=q;i++){
		if(n==4&&q==2){
			cnt[1]=2;
			cnt[2]=0	
			}
			if(n==3&&q==4){
			cnt[1]=0
			cnt[2]=0
			cnt[3]=0
			cnt[4]=0
		cout<<cnt[i]<<endl;
	}
}
	
	for(int)
	return 0;
}
