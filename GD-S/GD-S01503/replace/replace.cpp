#include<iostream> 
#include<algorithm> 
#include<cstdio> 
#include<cmath>

using namespace std;
const int N=2e5+86;
int n,q,ans,t1b,t2b,s1b[N],s2b[N];
string s1[N],s2[N],t1,t2;
char c;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		c=getchar();
		while(c!=' '){
			s1[i]+=c;
			if(c=='b')s1b[i]=s1[i].length();
			c=getchar();
		}
		int ttt=s1[i].length();
		c=getchar();for(int m=0;m<ttt;m++){
			s2[i]+=c;
			
			if(c=='b')s2b[i]=s2[i].length();
			c=getchar();
			
		}
	}
	for(int i=0;i<q;i++){
		t1b=-1;t2b=-1;ans=0;
		cin>>t1>>t2;
		for(int j=0;t1b==-1||t2b==-1;j++){
			if(t1[j]=='b')t1b=j+1;
			if(t2[j]=='b')t2b=j+1;
		}
		//int b2l=t2.length()-t2b-1;
		//int b1l=t1.length()-t1b-1;
		int lll=t2b-t1b;
		if(lll==0){
			for(int j=0;j<n;j++){
				if(s1[j]==s2[j]&&s1b[j]<=t1b&&s1[j].length()-s1b[j]<=t1.length()-t1b)ans++;
			}
		}
		else if(lll<0){
			for(int j=0;j<n;j++){
				int adad=s2b[j]-s1b[j];
				if(adad==lll&&s1[j].length()-s1b[j]<=t1.length()-t1b&&s2b[j]<=t2b)ans++;
			}
		}
		else{
			for(int j=0;j<n;j++){
				int adad=s2b[j]-s1b[j];
				if(adad==lll&&s2[j].length()-s2b[j]<=t2.length()-t2b&&s1b[j]<=t1b)ans++;
			}
		}
		
	printf("%d\n",ans);
	}
	return 0;
}
