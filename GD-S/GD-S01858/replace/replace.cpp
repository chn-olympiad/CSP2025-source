#include<bits/stdc++.h>
using namespace std;
const int N=10001,M=20001;
int n,q,len1[N],len2[N],c1len,c2len;
char s1[N][M],s2[N][M];
char c1[M];

string x,y,z,c2,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	if(n>N){
		while(q--)
			printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;++i){
		scanf("%s %s",s1[i]+1,s2[i]+1);
//		printf("%s %s\n",s1[i]+1,s2[i]+1);
		len1[i]=strlen(s1[i]+1);
		len2[i]=strlen(s2[i]+1);
	}
	
	int ans=0;
	while(q--){
		ans=0;
		x="",y="",z="",t="";
		
		scanf("%s",c1+1);
		c1len=strlen(c1+1);
		cin>>c2;
		
		if(c1len!=(int)c2.size()){
			printf("0\n");
			continue;
		}
		
		for(int j=1;j<=n;++j){
			bool f=false;
			x="",y="",z="",t="";
			for(int i=1;i<=c1len;++i){
				if(f){
					z+=c1[i];
					continue;
				}
				if(s1[j][1]!=c1[i]){
					x+=c1[i];
					continue;
				}
				for(int k=1;(k<=len1[j])&&(i<=c1len);++k,++i){
					if(s1[j][k]==c1[i]){
						y+=s2[j][k];
						t+=c1[i];
					}else{
						x+=t;
						t="";
						y="";
						break;
					}
					if(k==len1[j]){
						f=true;
						break;
					}
				}
			}
//			cout<<"x+y+z:"<<x+y+z<<endl;
			if(x+y+z==c2)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
