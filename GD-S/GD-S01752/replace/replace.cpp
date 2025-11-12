#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string s1[N],s2[N],t1[N],t2[N];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s1[i];
		cin>>s2[i];
	}
	for (int i=1;i<=q;i++){
		int ans=0;
		cin>>t1[i];
		cin>>t2[i];
		int len1=t1[i].size();
		for (int j=0;j<len1;j++){
//			if (t1[i][j]!=t2[i][j]){
				for (int k=1;k<=n;k++){
					int flag=1;
					int len2=s1[k].size();
//					if (j+len2>len1) continue;
					for (int h=j;h<j+len2;h++){
						if (h>len1){
							flag=0;
							break;
						}
						if (t1[i][h]!=s1[k][h-j]||t2[i][h]!=s2[k][h-j]){
							flag=0;
							break;
						}
					}
					if (flag){
						cout<<s1[k]<<"¡¡"<<s2[k]<<endl;
						ans++;
					}
				}
//			}
			
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
//noooooooo 
