#include <bits/stdc++.h>
using namespace std;
string s01[200005];
string s02[200005];
int a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s01[i]>>s02[i];
		int l=s01[i].size();
		for(int j=0;j<l;j++){
			if(s01[i][j]!=s02[i][j]){
				a[i]++;
			}
		}
		//cout<<a[i]<<" ";
	}
	//cout<<endl;
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		long long ans=0;
		int ss=0;
		int l=s1.size(),m=s2.size();
	//	cout<<"\n";
		if(l!=m){
			
		}
		else{
			for(int i=0;i<n;i++){
				if(s1[i]!=s2[i]){
					ss++;
				}
			}
		//	cout<<ss<<endl;
			for(int i=1;i<=n;i++){
				if((s1.find(s01[i])==s2.find(s02[i]))&&(ss==a[i])){
					int q=s1.find(s01[i]);
					//cout<<q<<" "<<l<<endl;
					if(q<l&&q>=0){
						//cout<<s1.find(s01[i])<<" "<<s2.find(s02[i])<<endl;
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a





 
*/
