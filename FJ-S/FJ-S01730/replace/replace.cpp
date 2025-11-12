#include<bits/stdc++.h>
using namespace std;
int n,q,l,L,R,M;
long long ans;
char x[108][208],y[108][208];
char a[2008],b[2008],t;
int ll[200008],rr[200008],m[200008];
bool check1(char *st,char *pt,int lgt){
	for(int i=0;i<strlen(pt);i++){
		if(st[i+lgt]!=pt[i]) return false;
	}
	return true;
}
bool check2(char *st,char *pt,int lf,int rt,char *tgt){
	for(int i=0;i<strlen(st);i++){
		if(lf<=i && i<=rt){
			if(pt[i-lf]!=tgt[i]){return false;}
		}else{
			if(st[i]!=tgt[i]){return false;}
		}
	}
	return true;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	if(n<=1){
		for(int i=1;i<=n;i++){
			scanf("%s",x[i]);
			scanf("%s",y[i]);
		}
		while(q--){
			ans=0;
			scanf("%s",a);
			scanf("%s",b);
			if(strlen(a)==strlen(b)){
				l=strlen(a);
			}else{
				printf("0\n");
				continue;
			}
			for(int i=1;i<=n;i++){
				if(l<strlen(x[i])){continue;}
				for(int j=0;j<=l-strlen(x[i]);j++){
					if(check1(a,x[i],j)){
						if(check2(a,y[i],j,j+strlen(y[i])-1,b)){
							ans++;
						}
					}
				}
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%s",a);
		scanf("%s",b);
		int xx=0,yy=0;
		for(int j=0;j<strlen(a);j++){
			if(a[j]=='b'){
				xx=j;
				break;
			}
		}
		for(int j=0;j<strlen(b);j++){
			if(b[j]=='b'){
				yy=j;
				break;
			}
		}
		ll[i]=(xx>yy)?xx:yy;
		rr[i]=(xx<yy)?(strlen(a)-xx-1):(strlen(b)-yy-1);
		m[i]=xx-yy;
	}
	while(q--){
		ans=0;
		scanf("%s",a);
		scanf("%s",b);
		int xxx=0,yyy=0;
		for(int j=0;j<strlen(a);j++){
			if(a[j]=='b'){
				xxx=j;
				break;
			}
		}
		for(int j=0;j<strlen(b);j++){
			if(b[j]=='b'){
				yyy=j;
				break;
			}
		}
		L=(xxx>yyy)?xxx:yyy;
		R=(xxx<yyy)?(strlen(a)-xxx-1):(strlen(b)-yyy-1);
		M=xxx-yyy;
		//printf("%d %d %d\n",L,R,M);
		for(int i=1;i<=n;i++){
			if(m[i]==0) continue;
			if(L>=ll[i] && R>=rr[i] && M==m[i]){
				ans++;
			}
		}
		printf("%lld\n",ans);		
	}
	return 0;
}
