#include<cstdio>
#include<map>
int n,q;
char s[2][5000005],t[2][5000005];
char S[10000005];
long long sd=107,bd=9000000000000421;
long long hash(){
	long long res=0;
	for(int i=1;S[i];i++){
		res=(res*sd+S[i]-'a'+1);
	}
	return res;
}
std::map<long long,bool> h;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s[0]+1,s[1]+1);
		int len=0;
		while(s[0][len+1]){
			len++;
		}
		for(int i=1;i<=len;i++){
			S[i]=s[0][i];
		}
		for(int i=len+1;i<=(len<<1);i++){
			S[i]=s[1][i-len];
		}
		S[len<<1|1]=0;
		h[hash()]++;
	}
	while(q--){
		int ans=0;
		scanf("%s%s",t[0]+1,t[1]+1);
		int len=0;
		while(t[0][len+1]){
			len++;
		}
		for(int i=1;i<=len;i++){
			S[i]=t[0][i];
		}
		for(int i=len+1;i<=(len<<1);i++){
			S[i]=t[1][i-len];
		}
		S[len<<1|1]=0;
		int x=1,y=len;
		while(t[0][x]==t[1][x]){
			x++;
		}
		while(t[0][y]==t[1][y]){
			y--;
		}
		if(x>y){
			ans=h[hash()];
		}else{
			for(int i=1;i<=x;i++){
				for(int j=y;j<=len;j++){
					for(int k=1;k<=(j-i+1);k++){
						S[k]=t[0][k+i-1];
					}
					for(int k=j-i+2;k<=((j-i+1)<<1);k++){
						S[k]=t[1][k+i-1-j+i-1];
					}
					S[(j-i+1)<<1|1]=0;
					ans+=h[hash()];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
