#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	bool flagA=true,flagB=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flagA=false,flagB=false;
		else if(a[i]==0) flagA=false;
	}
	if(flagA) cout<<n/2;
	else if(flagB){
		int ansa=0,ansb=0;
		for(int i=1;i<=n;i++)
			if(a[i]==0) ansa++;
			else ansb++;
		if(k==0) cout<<ansa+ansb/2;
		else cout<<ansb;
	}else{
		int kss[25]={0};
		stack<int> p;
		int sn=k,cnt=0;
		while(sn>0){
			int st=sn%2;
			sn/=2,p.push(st);
		}
		while(!p.empty()){
			int tp=p.top();
			p.pop(),cnt++;
			kss[cnt]=tp;
		}
		kss[0]=cnt;
		int s[n+1][25]={0};
		for(int i=1;i<=n;i++){
			if(a[i]==k) continue;
			stack<int> p;
			int sn=a[i],cnt=0;
			while(sn>0){
				int st=sn%2;
				sn/=2,p.push(st);
			}
			while(!p.empty()){
				int tp=p.top();
				p.pop(),cnt++;
				s[i][cnt]=tp;
			}
			s[i][0]=cnt;
		}
		int idx=1,ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=k){idx=i;break;} 
		for(int i=1;i<=n;i++)
			if(a[i]==k) ans++;
		for(int i=idx+1;i<=n;i++){
			if(a[i]==k) idx=i+1;
			else{
				int j;
				for(j=1;j<=min(s[idx][0],s[i][0]);j++)
					if(s[i][j]==s[idx][j]) s[idx][j]=0;
					else s[idx][j]=1;
				j--;
				if(j<s[i][0]) {
					j++;
					for(;j<=s[i][0];j++){
						if(s[i][j]==1){
							for(int k=s[i][0];k>=1;k--)
								s[i][k+1]=s[i][k];
							s[idx][1]=1,s[idx][0]++;
						}
						else{
							for(int k=s[i][0];k>=1;k--)
								s[i][k+1]=s[i][k];
							s[idx][1]=0,s[idx][0]++;
						}
					}
				}
				if(kss[0]==s[idx][0]){
					bool flag=true;
					for(j=1;j<=kss[0];j++)
						if(kss[j]!=s[idx][j]){
							flag=false;
							break;
						}
					if(flag) ans++,idx=i+1;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
