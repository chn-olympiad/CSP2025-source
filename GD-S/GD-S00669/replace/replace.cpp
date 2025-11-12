#include<bits/stdc++.h>
using namespace std;
#define FOR_R(i,a,b)	for(int i=a;i<=b;i++)
string s[100010][2],l1,l2;
int n,q,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>q;
	FOR_R(i,1,n)	cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>l1>>l2;
		ans=0;
		int lena=l1.length(),lenb=l2.length();
		if(lena!=lenb)	{
			cout<<"0\n";
			continue;
		}
		int mn=1000000,mx=0;
		FOR_R(i,0,lena){
			if(l1[i]!=l2[i]){
				mn=min(mn,i);mx=max(mx,i);
			}
		}
		int k=0;
		FOR_R(j,1,n){
			int bz=0;
			FOR_R(i,0,lena-1){
				if(l1[i]==s[j][0][k])	k++;
				else k=0;
				if(k==s[j][0].length())	{
					if(i-s[j][0].length()+1<=mn&&i>=mx){
						bz=1;
						FOR_R(l,i-s[j][0].length()+1,i){
							if(l2[l]!=s[j][1][l-(i-s[j][0].length()+1)])	{
								bz=0;
								break;
							}
						}
					}
				}
				if(bz)	break;	
			}	
			if(bz)	ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
