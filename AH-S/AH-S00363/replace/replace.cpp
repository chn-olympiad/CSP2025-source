#include<bits/stdc++.h>
using namespace std;
long long n,q,lw,rw,si[200005];
string a1[200005],a2[200005],s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
		si[i]=a1[i].size();
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		long long cnt=0,len=s1.size();
		for(int j=0;j<len;j++){
			if(s1[j]!=s2[j]){
				lw=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				rw=j;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(si[j]>=rw-lw+1&&si[j]<=len){
				string f1="",f2="";
				for(int k=rw-si[j]+1;k<=rw;k++){
					f1=f1+s1[k];
					f2=f2+s2[k];
				}
				if(f1==a1[j]&&f2==a2[j])cnt++;
				for(int k=rw+1;k<=lw+si[j]-1;k++){
					f1.erase(f1.begin());
					f2.erase(f2.begin());
					f1=f1+s1[k];
					f2=f2+s2[k];
					if(f1==a1[j]&&f2==a2[j])cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
