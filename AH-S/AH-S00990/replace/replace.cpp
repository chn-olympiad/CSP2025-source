#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
string t1,t2;
int main(){
        freopen("replace.in","r",stdin);
        freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		int len1=t1.size(),t=0;
		for(int i=0;i<len1;i++){
			if(t1[i]!=t2[i]){
				++t;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			int len2=s1[i].size(),j=0,num=0;
			for(;j<len2&&len2>=t;j++){
				for(int k=0;k<len1;k++){
					if(s1[i][j]==t1[k]&&s2[i][j]==t2[k]){
						if(t1[k]!=t2[k]){
							num++;
						}
					}
				}
			}
			if(num==t) cnt++;
		}
		cout<<cnt<<endl;
	}
        return 0;
} 
