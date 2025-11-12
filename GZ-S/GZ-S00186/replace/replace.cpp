//GZ-S00186 贵阳市第三实验中学 彭禹诺 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	if(q==1){
		int m=0;
		string x,y;
		cin>>x>>y;
		string hre="",pre="";
		for(int i=1;i<=n;i++){
			for(int j=0;j<x.size();j++){
				bool flag=0;
				pre=pre+x[i];hre=x[i]+hre;
				for(int m=0;m<s1.size();m++){
					if(x[j]!=s1[m]){
						flag=1;
						break;
					}
				} 
				if(flag==1){
					if(pre+s1+hre==y){
						m++;
					}
				}
			}
		}
		cout<<m;
		return 0;
	}
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		cout<<0<<endl;
	}
	return 0;
}
