#include<bits/stdc++.h>
using namespace std;
#define N 200005
string a[N],b[N],s1,s2;
int n,q;
bool che(int x1,int x2,int l,string s1,string s2){
	for(int i=0;i<l;i++)
		if(s1[x1+i]!=s2[x2+i])
			return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(q--){
		cin>>s1>>s2;
		int l1=s1.size(),l2=s2.size(),ans=0;
		for(int i=0;i<l1;i++){
			for(int j=1;j<=n;j++){
				int l3=a[j].size(),l4=b[j].size();
				if(l1-l3!=l2-l4)
					continue;
				if(che(0,0,i,s1,s2)&&che(i,0,l3,s1,a[j])
				&&che(i,0,l4,s2,b[j])&&che(i+l3,i+l4,l1-l3-i,s1,s2))
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
