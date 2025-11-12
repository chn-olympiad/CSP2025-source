#include<bits/stdc++.h>
using namespace std;
int n,m;
string ss;
bool s[550];
int c[550];
bool dd[550];
int ans;
int hjm(int no,int hav,int t){
	if(t<n){
			
		for(int i=1;i<=n;i++){
			if(dd[i]==0){
				if(s[t]==0){//难
					dd[i]=1;
					hjm(no+1,hav,t+1);
					dd[i]=0;
				}
				
				if(s[t]==1){//好
					if(no>=c[i]){
						dd[i]=1;
						hjm(no+1,hav,t+1);
						dd[i]=0;
					}
					else{
						dd[i]=1;
						hjm(no,hav+1,t+1);
						dd[i]=0;
					}
				}
			}
		}	
	}else{
		if(hav>=m){
			ans++;
		}
	}


	
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>ss;
	for(int i=0;i<ss.size();i++){
		if(ss[i]=='0'){//不过 
			s[i]=0;
		}
		else if(ss[i]=='1')s[i]=1;//过 
	}
	
	
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
	}
	hjm(0,0,0);
    cout<<ans;
	return 0;
}
