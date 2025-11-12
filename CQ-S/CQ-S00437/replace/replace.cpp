#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e5+10,L=2e6+10;
string s[N],s1[N];
string t,t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t>>t1;
		int sum=0;
		for(int j=0;j<t.size();j++){
			for(int k=1;k<=n;k++){
				bool flag=0;
				for(int l=0;l<s[k].size();l++){
					if(t[j+l]!=s[k][l]){
						flag=1;
						break;
					}
				}
				if(!flag){
					t2=t;
					for(int l=0;l<s1[k].size();l++){
						t2[j+l]=s1[k][l];
					}
					if(t2==t1)sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

