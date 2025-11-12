#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,Ln=5e5+5;
string sr1,sr2;
int n,Q,d[Ln],s[Ln],ch[Ln][26][26],t,as;
void cx(int p,int r,int ln){
	//printf("%d %d %d**************\n",p,r,ln);
	int i,c1,c2;
	for(i=r+1;i<ln;++i){
		as+=s[p];
		c1=sr1[i]-'a';
		c2=sr2[i]-'a';
		if(!ch[p][c1][c2]){
			break;
		}
		p=ch[p][c1][c2];
	}
	if(i==ln){
		as+=s[p];
	}	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i,j,c1,c2,ln,l,r,p;
	scanf("%d%d",&n,&Q);
	for(c1=0,i=1;i<=n;++i){
		cin>>sr1>>sr2;
		sr1=' '+sr1;
		sr2=' '+sr2;
		ln=sr1.size();
		for(l=1;l<ln&&sr1[l]==sr2[l];++l){
			
		}
		for(r=ln-1;r&&sr1[r]==sr2[r];--r){
			
		}
		for(p=0,j=l;j<=r;++j){
			//printf("%d ",p);
			c1=sr1[j]-'a';
			c2=sr2[j]-'a';
			if(!ch[p][c1][c2]){
				ch[p][c1][c2]=++t;
			}
			p=ch[p][c1][c2];
		}
		//printf("\n");
		if(!d[p]){
			d[p]=++t;
		}	
		//printf("d[%d]=%d\n",p,d[p]);
		for(p=d[p],j=l-1;j;--j){
			//printf("%d ",p);
			c1=sr1[j]-'a';
			c2=sr2[j]-'a';
			if(!ch[p][c1][c2]){
				ch[p][c1][c2]=++t;
			}
			p=ch[p][c1][c2];
		}
		//printf("\n");
		if(!d[p]){
			d[p]=++t;
		}
		++s[p];
		//printf("d[%d]=%d\n",p,d[p]);
		for(p=d[p],j=r+1;j<ln;++j){
			//printf("%d ",p);
			c1=sr1[j]-'a';
			c2=sr2[j]-'a';
			if(!ch[p][c1][c2]){
				ch[p][c1][c2]=++t;
			}
			p=ch[p][c1][c2];
		}
		//printf("p=%d\n",p);
		++s[p];
	}	
	while(Q--){
		cin>>sr1>>sr2;
		sr1=' '+sr1;
		sr2=' '+sr2;
		if(sr1.size()!=sr2.size()){
			printf("0\n");
			continue;
		}
		ln=sr1.size();
		as=0;
		for(l=1;l<ln&&sr1[l]==sr2[l];++l){
			
		}
		for(r=ln-1;r&&sr1[r]==sr2[r];--r){
			
		}		
		for(p=0,i=l;i<=r;++i){			
			c1=sr1[i]-'a';
			c2=sr2[i]-'a';
			if(!ch[p][c1][c2]){
				break;
			}
			p=ch[p][c1][c2];
			//printf("%d ",p);
		}
		//printf("l=%d r=%d p=%d i=%d\n",l,r,p,i);
		//printf("\n");
		if(i<=r||!d[p]){
			printf("0\n");
			continue;
		}		
		for(p=d[p],i=l-1;i;--i){
			//printf("%d ",p);
			if(s[p]){
				cx(d[p],r,ln);
			}
			c1=sr1[i]-'a';
			c2=sr2[i]-'a';
			if(!ch[p][c1][c2]){
				break;
			}
			p=ch[p][c1][c2];
		}
		//printf("l=%d r=%d\n",l,r);
		if(!i&&s[p]){
			cx(d[p],r,ln);
		}
		//printf("\n");
		//printf("1\n");
		printf("%d\n",as);
	}
	return 0;
} 
