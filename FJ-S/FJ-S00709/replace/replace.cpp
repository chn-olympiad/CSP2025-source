#include <cstdio>
#define MAXN 200005
#define MAXL 5000005
#define spac putchar(' ')
#define nxln putchar('\n')
using namespace std;

int n,q,s1ind[MAXN],s2ind[MAXN],prelen,ans;
int s1pre[MAXN],s2pre[MAXN],s1pos[MAXN],s2pos[MAXN],t1pre,t1pos,t2pre,t2pos,t1len,t2len;
char s1[MAXL],s2[MAXL],t1[MAXL],t2[MAXL];

int read(){
	int rx=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		rx=rx*10+ch-'0';
		ch=getchar();
	}
	
	return rx;
}
void write(int x){
	static int sta[52];
	int top=0;
	do{
		sta[top++]=x%10;
		x/=10;
	}while(x);
	while(top)putchar(sta[--top]+'0');
}
int readstr(int index, char str[]){
	int len=0;
	char ch=getchar();
	while(ch<'a'||ch>'z')ch=getchar();
	while(ch>='a'&&ch<='z'){
		if(ch=='b'){
			prelen=len;
		}
		str[index++]=ch;++len;
		ch=getchar();
	}
	
	return len;
}
/*void writestr(int index, char str[], int nextindex){
	int len=nextindex-index;
	for(int i=0;i<len;++i){
		putchar(str[index++]);
	}
}*/

void solveB(){
	for(int i=0;i<n;++i){
		s1ind[i+1]=s1ind[i]+readstr(s1ind[i],s1)+1; // read s_i,1
		s1pre[i]=prelen;s1pos[i]=s1ind[i+1]-s1ind[i]-prelen-2;
		s2ind[i+1]=s2ind[i]+readstr(s2ind[i],s2)+1; // read s_i,2
		s2pre[i]=prelen;s2pos[i]=s2ind[i+1]-s2ind[i]-prelen-2;
		//printf("i=%d: s1ind[i+1]:%d, s2ind[i+1]:%d\n",i,s1ind[i+1],s2ind[i+1]);
	}
	for(int j=0;j<q;++j){
		ans=0;
		t1len=readstr(0,t1); // read t_j,1
		t1pre=prelen;t1pos=t1len-prelen-1;
		t2len=readstr(0,t2); // read t_j,2
		t2pre=prelen;t2pos=t2len-prelen-1;
		
		int movebit=t1pre-t2pre;
		
		for(int i=0;i<n;++i){
			if(s1pre[i]-s2pre[i]==movebit){
				if(s1pre[i]<=t1pre&&s1pos[i]<=t1pos)ans++;
			}
		}
		write(ans);nxln;
	}
	/*for(int i=0;i<n;++i){
		writestr(s1ind[i], s1, s1ind[i+1]);spac;
		writestr(s2ind[i], s2, s2ind[i+1]);spac;
		
		printf("t1:%d,%d t2:%d,%d\n",s1pre[i],s1pos[i],s2pre[i],s2pos[i]);
	}*/
	
	return;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n=read();q=read();
	
	//special A solve
	/*if(q==1){
		solveA();
	}*/
	//special B solve
	solveB();
	
	return 0;
}
