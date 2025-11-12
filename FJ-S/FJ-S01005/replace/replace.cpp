#include<bits/stdc++.h>
using namespace std;
long long n,Q,ans;
string s[200000][2];//n
string t[200000][2];//q
void kmp(long long lens,long long u,long long v,long long lent){
	printf("%lld %lld, %lld %lld{\n",u,v,lens,lent);
	long long jump[lent],i,j=0;
	long long p=0,q=0;
	memset(jump,0,sizeof(jump)); 
	jump[0]=-1;
//	printf("<%lld %lld>\n",lens,lent);
	for(q=1;q<lent-1;q++){
//		printf("[%lld %lld]\n",p,q);
		if(t[v][0][q]==t[v][0][p]&&t[v][1][q]==t[v][1][p]){
			jump[q+1]=p+1;
			p++;
		}
		else{
			p=jump[p];
			if(p!=-1)q--;
			else{
				p=0;
			}
		}
	}
	for(i=0;i<lent;i++){
		printf("%lld ",jump[i]);
	}
	printf("\n\n");
    j=0;
	for(i=0;i<lens;i++){
		if(s[u][0][i]==t[v][0][j]&&s[u][1][i]==t[v][1][j]){
			if(j==lent-1){
			//	printf(">>%lld\n",i);
			ans++;
				i--;
				j=jump[j];
			}
			else j++;
		}
		else{
			j=jump[j];
			if(j!=-1)i--;
			else j=0;
		}
	}
}
void worktypeA(){
	long long i_q,i,j;
	for(i_q=0;i_q<Q;i_q++){
		ans=0;
		for(i=0;i<n;i++){
		/*
			if(lent<rpR-rpL+1)continue;
			long long L=0;
			for(j=0;j<lent;j++){
				if(t[i][0][j]==t[i][1][j]&&t[i][0][j]==s[i_q][0][j]&&j<rpL)L++;
				else break;
			}*/ 
			kmp(s[i_q][0].size(),i_q,i,t[i][0].size());
		}
		printf("%lld\n",ans);
	}
	return;
}
void worktypeB(){
	return;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>Q;
	long long i,j;
	for(i=0;i<n;i++)cin>>s[i][0]>>s[i][1];
	for(i=0;i<Q;i++)cin>>t[i][0]>>t[i][1];
	worktypeA();
	return 0;
}

