#include<bits/stdc++.h>
using namespace std;
string s2[200005];
struct Akano{
	vector<int> chan;
	int sun[27];
}asd[500000];
//AC自动机
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	int cnt=0;
	scanf("%d%d",&n,&q);
	char c=0;
	
	for(int i=1;i<=n;++i){
		while(c!='\n')c=getchar();
		string c1;
		{
			int i=0;
			c=getchar();
			while(c!=' '){c1[i]=c,c=getchar();}
			
		}
		
		{
			int i=0;
			c=getchar();
			while(c>'z' || c<'a'){c1[i]=c,c=getchar();}
			
		}
		cin>>c1>>s2[i];
		int siz=c1.size();
		int num=0;
		for(int j=0;j<siz;++j){
			int v=c1[j]-'a';
			if(!asd[num].sun[v]){
				asd[num].sun[v]=++cnt;
				num=cnt;
			}
			else num=asd[num].sun[v];
		}
		asd[num].chan.push_back(i);
	}
	int ans=0;
//	printf("1111111\n");
	for(int i=1;i<=q;++i){
		while(c!='\n')c=getchar();
		string a,b;
		{
			int i=0;
			c=getchar();
			while(c!=' '){a[i]=c,c=getchar();}
			
		}
		
		{
			int i=0;
			c=getchar();
			while(c>'z' || c<'a'){b[i]=c,c=getchar();}
			
		}
		int siz=a.size();
		for(int l=0;l<siz;++l){
			int num=0;
			for(int j=l;j<siz;++j){
				int v=a[j]-'a';
				if(!asd[num].sun[v]){
					break;
				}
				else {
					num=asd[num].sun[v];
					if(!asd[num].chan.empty()){
						for(auto i:asd[num].chan){
							string c3=a;
							for(int p=j;p>=l;--p){
								c3[p]=s2[i][p];
							}
							if(c3==b)ans++;
						}
					}
				}
			}
		}
		
		printf("%d\n",ans);
		
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aabb
xabcx xadex
aaaa bbbb
*/