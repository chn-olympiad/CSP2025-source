# include <bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b;
	int c;
}st[100005];
int t,n,j;
int limit;
int ans=0;
int a,b,c;
int pa=0,pb=0,pc=0;
int e[5];
int va[100005]={0},vb[100005]={0},vc[100005]={0};
int via,vib,vic;
int ka,kb,kc;


void notice(){
	if(e[1]==a){
		pa++;
		va[via]=j;
		ka=va[via];
		via++;
	}
	else if(e[1]==b){
		pb++;
		vb[vib]=j;
		kb=vb[vib];
		vib++;
	}
	else if(e[1]==c){
		pc++;
		vc[vic]=j;
		kc=vc[vic];
		vic++;
	}
	return;
}
void compaira(){
	if(pa>limit){
		pa--;
		ans=ans-st[ka].a;
	    e[1]=-1;
	    e[2]=st[ka].b;
	    e[3]=st[ka].c;
	    sort(1,4);
		via--;
	    notice();
	    ans=ans+e[1];
		}
	    return ;
}
void compairb(){
	if(pb>limit){
		pb--;
		ans=ans-st[kb].b;
		e[1]=st[kb].a;
	    e[2]=-1;
	    e[3]=st[kb].c;
	    sort(1,4);
		vib--;
	    notice();
	    ans=ans+e[1];
	}
	return ;
}
void compairc(){
	if(pc>limit){
		pc--;
		ans=ans-st[kc].c;
		e[1]=st[kc].a;
	    e[2]=st[kc].b;
	    e[3]=-1;
	    sort(1,4);
		vic--;
	    notice();
	    ans=ans+e[1];
	}
	return ;
}
void compair(){
	compaira();
	compairb();
	compairc();
	if(pa<limit&&pb<limit&&pc<limit)return;
	compair();
}

int add(int a,int b,int c){
	e[1]=a;
	e[2]=b;
	e[3]=c;
	sort(1,4);
	notice();
	ans=ans+e[1];
	compair();
	return ans;
}

int solve(){
	for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a,&b,&c);
		    st[j].a=a;
		    st[j].b=b;
		    st[j].c=c;
		    va[1]=st[1].a;
		    vb[1]=st[1].b;
		    vc[1]=st[1].c;
		    e[1]=a;
	        ans=add(a,b,c);
		}
	return ans;
}
int main (){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		int limit=n/2;
		via=1,vib=1,vic=1;
		ans=solve();
		printf("%d\n",ans);
	}
	
    fclose(stdin);
	fclose(stdout); 
		return 0;
}
