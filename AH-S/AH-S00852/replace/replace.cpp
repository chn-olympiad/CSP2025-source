#include<bits/stdc++.h>
using namespace std;
int n,m;
string q1,q2,s1[1005],s2[1005];
bool check(int i,int j){
	string str=q1;
	int ll=s1[j].size();
	for(int k=i;k<=i+ll-1;k++){
		if(q1[k]!=s1[j][k-i])return 0;
		str[k]=s2[j][k-i];
	}
	return str==q2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(m--){
        int ans=0;
        cin>>q1>>q2;	
        int l=q2.size();
        for(int i=0;i<l;i++){
			for(int j=1;j<=n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
