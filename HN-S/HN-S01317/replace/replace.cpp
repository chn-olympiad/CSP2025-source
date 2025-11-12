#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s[100001][3];
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		string s3,s4;
		int ans=0;
		cin>>s3>>s4;
		int l,r;
		for(int i=1;i<=n;i++){
			if(s[i][1]==s3&&s[i][2]==s4) ans++; //x,yÎª¿Õ 
		}
		for(int i=0;i<s3.size();i++){
			if(s3[i]!=s4[i]&&l==0) l=i;
			if(s4[i]==s4[i]&&l!=0) r=i; 
		}
		bool flag=false;
		for(int i=0;i<l;i++){
			if(s3[i]!=s4[i]) flag=true,break;
		}
		int op;
		for(int i=1;i<=n;i++){
			flag=false;
			for(int j=l;j<=r;j++){
				if(s[i][1][j-l]!=s3[j]) flag=true,break;
			}
			if(!flag) op=i,break;
		}
		for(int i=l;l<=r;i++){
			if(s[op][2][i-l]!=s4[i]) flag=true,break;
		}
		for(int i=r+1;i<s3.size();i++){
			if(s3[i]!=s4[i]) flag=true,break;
		}
		if(flag==false) ans++;
		//x,y·Ç¿Õ 
		bool flag=false;
		int op;
		for(int i=1;i<=n;i++){
			flag=false;
			for(int j=0;j<=r;j++){
				if(s[i][1][j-l]!=s3[j]) flag=true,break;
			}
			if(!flag) op=i,break;
		}
		for(int i=0;l<=r;i++){
			if(s[op][2][i-l]!=s4[i]) flag=true,break;
		}
		for(int i=r+1;i<s3.size();i++){
			if(s3[i]!=s4[i]) flag=true,break;
		}
		if(flag==false) ans++;
		
		bool flag=false;
		for(int i=0;i<l;i++){
			if(s3[i]!=s4[i]) flag=true,break;
		}
		int op;
		for(int i=1;i<=n;i++){
			flag=false;
			for(int j=l;j<s3.size();j++){
				if(s[i][1][j-l]!=s3[j]) flag=true,break;
			}
			if(!flag) op=i,break;
		}
		for(int i=l;l<s3.size();i++){
			if(s[op][2][i-l]!=s4[i]) flag=true,break;
		}
		if(flag==false) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
