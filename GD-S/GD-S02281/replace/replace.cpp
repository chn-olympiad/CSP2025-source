#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s1[N],s2[N],a1[N],a2[N];
int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(q!=1){
		for(int i=1;i<=q;i++)
		cout<<0<<"\n";
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string a1,a2;
		cin>>a1>>a2;
		for(int j=0;j<n;j++){
			int l=0,r=0,flag=0,o=0;
			for(int k=0;k<s1[j].size();k++){
				if(s1[j][k]==a1[k]&&flag==0){
					flag=1;
					l=k;
				}
				if(flag==1&&s1[j][k]!=a1[k]){
				r=k-1;	
				break;
				} 
			}
			for(int k=l;k<=r;k++){
				if(s2[j][k]!=a2[k]){
					break;	
				}
				else o++;
			}
			if(o==r-l+1) ans++;
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
