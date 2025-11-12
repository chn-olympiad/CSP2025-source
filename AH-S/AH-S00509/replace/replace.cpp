#include<bits/stdc++.h>
using namespace std;
string a[234567][3],t1,t2;
string fn(string kk,int qd,int ln){
	string ans="1";
	for(int i=1;i<ln;i++){
		ans+="1";
	}
	for(int i=qd,j=0;i<qd+ln;i++,j++){
		ans[j]=kk[i];
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	int ans=0;
	for(int mn=1;mn<=q;mn++){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			int len=a[i][1].size();int lt=t1.size();
			for(int j=0;j<=lt-len;j++){
				string zc=fn(t1,j,len);
				if(zc==a[i][1]){string tt=t1;
					
					for(int k=j,kkk=0;k<j+len;k++,kkk++){
						string anssss=a[i][2];
						tt[k]=anssss[kkk];
					}
					if(tt==t2)ans++;
				}
			}
		}
	
	cout<<ans<<endl;
	}
	return 0;
}
