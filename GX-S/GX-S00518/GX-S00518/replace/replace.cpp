#include<bits/stdc++.h>
//typedef long long ll;
using namespace std;
int n,p,ans;
string s[200009][3],t[200009][3];
string a="qwe",b="asd";
int ll[200009][3],rr[200009][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=p;i++)
		cin>>t[i][1]>>t[i][2];
	if(n<=100){
		
		for(int i=1;i<=p;i++){
			string tt=t[i][1],ttt=t[i][2];
			if(tt.size()!=ttt.size()){
				cout<<0<<endl;
				continue;
			}
			ans=0;
			for(int j=1;j<=n;j++){
				
				int wz=0,ok=1;
				string ss=s[j][1],sss=s[j][2];
				while(tt.find(ss,wz)!=a.find(b)){
					wz=tt.find(ss,wz);
					for(int k=0;k<(int)tt.size();k++){
						if(k>=wz&&k<=wz+(int)ss.size()-1){
							if(sss[k-wz]!=ttt[k]){
								ok=0;break;
							}
						}
						else 
							if(tt[k]!=ttt[k]){
								ok=0;break;
							}
					}
					wz+=ss.size();
					ans+=ok;
					
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			string tt=s[i][1],ttt=s[i][2];
			for(int j=0;j<(int)tt.size();j++){
				if(tt[j]=='b')break;
				ll[i][1]++;
			}
			for(int j=(int)tt.size()-1;j>=0;j--){
				if(tt[j]=='b')break;
				rr[i][1]++;
			}
			for(int j=0;j<(int)ttt.size();j++){
				if(ttt[j]=='b')break;
				ll[i][2]++;
			}
			for(int j=(int)ttt.size()-1;j>=0;j--){
				if(ttt[j]=='b')break;
				rr[i][2]++;
			}
		}
//--------------------------------------------------//

		for(int i=1;i<=p;i++){
			string tt=t[i][1],ttt=t[i][2];
			if(tt.size()!=ttt.size()){
				cout<<0<<endl;
				continue;
			}
			int l1=0,r1=0,l2=0,r2=0;
			for(int j=0;j<(int)tt.size();j++){
				if(tt[j]=='b')break;
				l1++;
			}
			for(int j=(int)tt.size()-1;j>=0;j--){
				if(tt[j]=='b')break;
				r1++;
			}
			for(int j=0;j<(int)ttt.size();j++){
				if(ttt[j]=='b')break;
				l2++;
			}
			for(int j=(int)ttt.size()-1;j>=0;j--){
				if(ttt[j]=='b')break;
				r2++;
			}
			for(int j=1;j<=n;j++){
				if(l1-ll[j][1]+ll[j][2]==l2)
					if(r1-rr[j][1]+rr[j][2]==r2)
						ans++;
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
