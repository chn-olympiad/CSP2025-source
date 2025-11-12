#include<bits/stdc++.h>
#define _ 5000005
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,q,L;
bool flagb=1;
string s[_][2],t[_][2];
int dif1[_],dif2[_],d[_],p1[_];
bool check(int i,int j,int k){
	for(int o=j;o<j+s[k][0].size();o++){
		if(s[k][0][o-j]!=t[i][0][o])return 0;
	}
	string now=t[i][0];
	for(int o=j;o<j+s[k][0].size();o++)now[o]=s[k][1][o-j];
	if(now==t[i][1])return 1;
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1],L+=s[i][0].size()+s[i][1].size();
		int a=0,b=0;
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]=='a')++a;
			if(s[i][0][j]=='b')++b;
		}
		flagb&=(a+b==s[i][0].size()&&b==1);
		a=0,b=0;
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][1][j]=='a')++a;
			if(s[i][1][j]=='b')++b;
		}
		flagb&=(a+b==s[i][1].size()&&b==1);
		a=0,b=0;
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1],L+=t[i][1].size()+t[i][2].size();
		int a=0,b=0;
		for(int j=0;j<t[i][0].size();j++){
			if(t[i][0][j]=='a')++a;
			if(t[i][0][j]=='b')++b;
		}
		flagb&=(a+b==t[i][0].size()&&b==1);
		a=0,b=0;
		for(int j=0;j<t[i][1].size();j++){
			if(t[i][1][j]=='a')++a;
			if(t[i][1][j]=='b')++b;
		}
		flagb&=(a+b==t[i][1].size()&&b==1);
		a=0,b=0;
	}
	if(flagb){
		for(int i=1;i<=n;i++){
			int pos1=-1,pos2=-1;
			for(int j=0;j<s[i][0].size();j++){
				if(s[i][0][j]=='b'){pos1=j;break;}
			}
			for(int j=0;j<s[i][1].size();j++){
				if(s[i][1][j]=='b'){pos2=j;break;}
			}
			d[i]=pos1-pos2,p1[i]=pos1;
			if(pos1-pos2>=0)dif1[pos1-pos2]++;
			else dif2[pos2-pos1]++;
		}
		for(int i=1;i<=q;i++){
			if(t[i][0].size()!=t[i][1].size())puts("0");
			else{
				int pos1=-1,pos2=-1;
				for(int j=0;j<t[i][0].size();j++){
					if(t[i][0][j]=='b'){pos1=j;break;}
				}
				for(int j=0;j<t[i][1].size();j++){
					if(t[i][1][j]=='b'){pos2=j;break;}
				}
				int ans=0;
				for(int i=1;i<=n;i++){
					if(p1[i]>=pos1&&pos1-pos2==d[i])++ans;
				}
				printf("%d\n",ans);
//				if(pos1-pos2>=0)printf("%d\n",dif1[pos1-pos2]);
//				else printf("%d\n",dif2[pos2-pos1]);	
			}
		}
	}else{
		for(int i=1;i<=q;i++){
			if(t[i][0].size()!=t[i][1].size())puts("0");
			else{
				int l=-1,r=-1,ans=0;
				for(int j=0;j<t[i][0].size();j++){
					if(t[i][0][j]!=t[i][1][j])
					if(l==-1)l=r=j;
					else r=j;
				}
				for(int j=0;j<=l;j++){
					for(int k=1;k<=n;k++){
						if(s[k][0].size()>=(r-j+1)){
							if(check(i,j,k))++ans;
						}
					}
				}
				printf("%d\n",ans); 
			}
		}
	}
//	if(n<=1000&&q<=1000&&L<=2000){
		
//	}
	return 0;
}
