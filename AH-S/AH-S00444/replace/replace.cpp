#include<bits/stdc++.h>
using namespace std;
int n,q,s1[200005][2],t1[200005][2];string s[200005][2],t[200005][2];
int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	if(q==1){
		int ans=0;for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
		cin>>t[1][0]>>t[1][1];
		for(int i=1;i<=n;i++){
			string a1=t[1][0],a2=t[1][1];
			for(int j=0;j<=int(a1.size()-s[i][0].size());j++)
			{
				if(a1.substr(j,j-1+int(s[i][0].size()))==s[i][0]
				&&a2.substr(j,j-1+int(s[i][1].size()))==s[i][1])
				{ans++;break;}
			}
		}
		write(ans);
		exit(0);
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];int b;
		for(int j=0;j<int(s[i][0].size());j++)
			if(s[i][0][j]=='b'){b=j;break;}
		for(int j=0;j<int(s[i][1].size());j++)
			if(s[i][1][j]=='b'){
				s1[i][0]=j-b;
				s1[i][1]=s[i][1].size()-s[i][0].size()+b-j;
				break;
			}
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];int b;
		for(int j=0;j<int(t[i][0].size());j++)
			if(t[i][0][j]=='b'){b=j;break;}
		for(int j=0;j<int(t[i][1].size());j++)
			if(t[i][1][j]=='b'){
				t1[i][0]=j-b;
				t1[i][1]=t[i][1].size()-t[i][0].size()+b-j;
				break;
			}
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++)
			if(s1[j][0]==t1[i][0]&&s1[j][1]==t1[j][1])ans++;
		write(ans);puts("");
	}
	return 0;
}
