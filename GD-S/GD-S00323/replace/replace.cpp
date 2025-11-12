#include<cstdio>
#include<cstdlib>
typedef long long LL;

const int N=400+3;

char *x, *y; char tmp[403], ttx[403], tty[403];

//----------字符串操作---------- 
int strlen(char *it) {
	int lambda=0;//字符串长度lambda 
	while((*it)!='\0') ++lambda, ++it;
	return lambda;
}
void in_a_string(char* &it) {
	scanf("%s",&tmp[1]);
	int len=strlen(&tmp[1]);
	it=new char[len+3];
	for(int j=1;j<=len;++j) it[j]=tmp[j];
	it[0]=it[len+1]=it[len+2]='\0';
}
//void put_in_a_string(char* &it, char *tmp) {
//	int len=strlen(&tmp[1]);
//	it=new char[len+3];
//	for(int j=1;j<=len;++j) it[j]=tmp[j];
//	tmp[0]=tmp[len+1]=tmp[len+2]='\0';
//}
char strcmp(char *it, char *iu) {
	while((*it)!='\0'&&(*iu)!='\0') {
		if((*it)!=(*iu)) return (*it)<(*iu)? '<':'>';//不等 
		else ++it, ++iu;
	} return '=';//两个字符串相等 
}

struct pair {
	char *first, *second; 
	pair(char *fffff=nullptr, char *sssss=nullptr) {first=fffff, second=sssss; }
} pr[N]; 
bool operator<(pair p1, pair p2) {
	char resu=strcmp(p1.second, p2.second);
	if(resu=='=') return (strcmp(p1.first,p2.first)=='<');
	else return resu=='<';
}
bool operator==(pair p1, pair p2) {return strcmp(p1.first,p2.first)=='='&&
	strcmp(p1.second,p2.second)=='='; }
bool OK(pair p1, char *p2) {return strcmp(p1.first,p2)=='='; } 

int lfind(pair *alpha, pair beta, int le, int ri) {
	for(int i=le;i<=ri;++i) if(alpha[i]==beta) return i; 
	return -1;
} 
int rfind(pair *alpha, pair beta, int le, int ri) {
	for(int i=ri;i>=ri;--i) if(alpha[i]==beta) return i; 
	return -1;
} 

LL dp[N];

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=0,q=0,nwn=0;
	scanf("%i%i",&n,&q);
	for(int i=1;i<=n;++i) {
		++nwn;
		in_a_string(pr[nwn].first), in_a_string(pr[nwn].second);
		if(lfind(pr, pr[nwn], 1, nwn-1)!=-1) --nwn;
	} n=nwn;
	for(;q>0;--q) {
		for(int i=0;i<N;++i) dp[i]=0;
		in_a_string(x), in_a_string(y);
		for(int i=1;i<=n;++i) {
			for(int j=0;j<i;++j) {
				int leng=0;
				for(int k=j+1;k<=i;++k) ttx[leng++]=x[k], tty[leng++]=y[k];
				tmp[leng]='\0';
				int pos1=lfind(pr,pair(ttx,tty),1,n), pos2=rfind(pr,pair(ttx,tty),1,n);
				if(pos1!=-1) dp[i]=dp[j]+(pos2-pos1+1);
			}
			dp[i]+=dp[i-1];
		} delete []x, delete []y, x=y=nullptr;
		printf("%lli\n",dp[n]);
	} 
	for(int i=1;i<=n;++i) delete []pr[i].first, delete []pr[i].second;
	return 0;
}
