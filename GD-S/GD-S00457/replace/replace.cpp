#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;string a[n+5][5]={""};
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2];
	while(q--){int s=0;
		string st,st2;cin>>st>>st2;
		int l=st.length();
		for(int i=1;i<=n;i++)
			if(a[i][1].size()<=l){
				string tmp="";
				for(int j=0;j<l-a[i][1].size()+1;j++){
					if(st[j]==a[i][1][0]){
						bool f=1;
						for(int z=1;z<a[i][1].size();z++)
							if(a[i][1][z]!=st[z+j]){f=0;break;}
						if(f){
							string t=tmp;t+=a[i][2];
							for(int z=j+a[i][1].size();z<l;z++)t+=st[z];
							if(t==st2){s++;}
						}
					}tmp+=st[j];
				}
			}cout<<s<<endl;
	} 
	return 0;
}
