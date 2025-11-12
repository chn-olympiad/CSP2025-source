#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
string ka,kb;
string la[200005],lb[200005];
int len[200005];
int tong[6000005];
int b1[200005],b2[200005];
int t1[200005],t2[200005];
inline bool check(int x,int y){
	if(y==12){
	//	cout<<len[x]<<" "<<b1[x]<<" "<<la[y].size()<<" "<<t1[y]<<endl;
	//	cout<<len[x]-b1[x]<<"#$#$$##$$"<<la[y].size()-t1[y]<<endl;
	//	cout<<b1[x]<<"??????????"<<t1[y]<<endl;
	}
	if(len[x]-b1[x]>la[y].size()-t1[y])return true;
	if(b1[x]>t1[y])return true;
	return false;
}
inline void work(){
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int l=1;l<=n;l++){
			if(b1[l]-b2[l]==t1[i]-t2[i]){
			//	cout<<114514<<endl;
				if(check(l,i)){
				//	cout<<"****"<<endl;
					continue;
				}
				ans++;
			}
			
		}
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
//	cout<<n<<"***"<<q<<endl;
	for(int i=1;i<=n;i++){
		cin>>(s[i][1])>>(s[i][2]);
		len[i]=s[i][1].size();
	}
	bool flag=false;
	for(int i=1;i<=n;i++){
		for(int l=0;l<len[i];l++){
			if(s[i][1][l]!='a'&&s[i][1][l]!='b')flag=true;
			if(s[i][2][l]!='a'&&s[i][2][l]!='b')flag=true;
			if(s[i][1][l]=='b')b1[i]=l;
			if(s[i][2][l]=='b')b2[i]=l; 
		}
	}
	for(int i=1;i<=q;i++)cin>>la[i]>>lb[i];
	if(flag==false){
		for(int i=1;i<=q;i++){
			int L=la[i].size();
			for(int l=0;l<L;l++){
				if(la[i][l]!='a'&&la[i][l]!='b')flag=true;
				if(lb[i][l]!='a'&&lb[i][l]!='b')flag=true;
				if(la[i][l]=='b')t1[i]=l;
				if(lb[i][l]=='b')t2[i]=l;
			}
		}
	//	cout<<114514<<endl;
		if(flag==false)work();
		return 0;
	}
	if(n>=1000){
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		ka=la[i];
		kb=lb[i];
		int L=ka.size();
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int l=1;l<=L-len[i]+1;l++){
				bool flag=false;
				for(int r=l;r<=l+len[i]-1;r++){
					if(s[i][1][r-l+1-1]!=ka[r-1]){
						flag=true;
						break;
					}
				}
				if(flag==false){
					bool w=0;
					for(int j=1;j<l;j++){
						if(ka[j-1]!=kb[j-1]){
							w=1;
							break;
						}
					}
					for(int j=l;j<=l+len[i]-1;j++){
						if(s[i][2][j-l+1-1]!=kb[j-1]){
							w=1;
							break;
						}
					}
					for(int j=l+len[i];j<=L;j++){
						if(ka[j-1]!=kb[j-1]){
							w=1;
							break;
						}
					}
					if(w==0){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl; 
	}
}
