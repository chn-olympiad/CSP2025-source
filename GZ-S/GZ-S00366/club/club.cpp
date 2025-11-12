#include <bits/stdc++.h>//GZ-S00366 都匀市第二中学 罗梓菡
using namespace std;

const int MAXN=1e5+1;
int T,ans;
struct node{
	int a,b,c;
	int maxx;
	char club;
}s[MAXN];
int pera[MAXN],perb[MAXN],perc[MAXN];//第i个人加入a\b\c部门的满意度 
int suma,sumb,sumc; 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	int t=T;
	while(t--){
		int n;
		ans=suma=sumb=sumc=0;
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].maxx=max(s[i].a,s[i].b);
			if(s[i].maxx==s[i].a) s[i].club='a';
			else s[i].club='b';
			int h=s[i].maxx;
			s[i].maxx=max(s[i].maxx,s[i].c);
			if(h!=s[i].maxx) s[i].club='c';			
		}
		/*for(int i=1;i<=n;i++)
			cout<<s[i].club<<":"<<s[i].maxx<<endl;*/
		for(int i=1;i<=n;i++){
			if(s[i].club=='a') pera[++suma]=s[i].maxx;
			else if(s[i].club=='b') perb[++sumb]=s[i].maxx;
			else perc[++sumc]=s[i].maxx;
		}
		if(suma<=m && sumb<=m && sumc<=m){
			for(int i=1;i<=suma;i++)
				ans+=pera[i];
			for(int i=1;i<=sumb;i++)
				ans+=perb[i];
			for(int i=1;i<=sumc;i++)
				ans+=perc[i];
			cout<<ans<<endl;
			break;
		}
	}
	return 0;
}
/*
		if(suma>m){
			int cha=suma-m;
			int chaa[MAXN];
			for(int i=1;i<=cha;i++)
				chaa[i]=20010;
			findminna(cha,suma);
			while(suma>m || sumb>m || sumc>m){
				findmaxx(n);
				chose(n,suma,sumb,sumc);
			}
			cot(suma,sumb,sumc);
			break;
		}
		if(sumb>m){
			int cha=sumb-m;
			int chaa[MAXN];
			for(int i=1;i<=cha;i++)
				chaa[i]=20010;
			findminnb(cha,sumb);
			while(suma>m || sumb>m || sumc>m){
				findmaxx(n);
				chose(n,suma,sumb,sumc);
			}
			cot(suma,sumb,sumc);
			break;
		}
		if(sumc>m){
			int cha=sumc-m;
			int chaa[MAXN];
			for(int i=1;i<=cha;i++)
				chaa[i]=20010;
			findminnc(cha,sumc);
			while(suma>m || sumb>m || sumc>m){
				findmaxx(n);
				chose(n,suma,sumb,sumc);
			}
			cot(suma,sumb,sumc);
			break;
		}
		
void findmaxx(int n){
	for(int i=1;i<=n;i++){
		s[i].maxx=max(s[i].a,s[i].b);
		if(s[i].maxx==s[i].a) s[i].club='a';
		else s[i].club='b';
		int t=s[i].maxx;
		s[i].maxx=max(s[i].maxx,s[i].c);
		if(t!=s[i].maxx) s[i].club='c';
	}
}
void chose(int n,int suma,int sumb,int sumc){
	for(int i=1;i<=n;i++){
			if(s[i].club=='a'){
				pera[++suma].name=i;
				pera[suma].number=s[i].maxx;
			}
			else if(s[i].club=='b'){
				perb[++sumb].name=i;
				perb[sumb].number=s[i].maxx;
			}
			else{
				perc[++sumc].name=i;
				perc[sumc].number=s[i].maxx;
		}
	}
}
void cot(int suma,int sumb,int sumc){
	int ans;
	for(int i=1;i<=suma;i++)
		ans+=pera[i].number;
	for(int i=1;i<=sumb;i++)
		ans+=perb[i].number;
	for(int i=1;i<=sumc;i++)
		ans+=perc[i].number;
	cout<<ans<<endl;
} 

//找最小并更改 
void findminna(int cha,int sumx){
	for(int i=1;i<=sumx;i++){
		for(int j=i+1;j<=sumx;j++){
			if(pera[i].number<pera[j].number){
				int name1,number1;
				name1=pera[i].name,number1=pera[i].number;
				pera[i].name=pera[j].name,pera[i].number=pera[j].number;
				pera[j].name=name1,pera[j].number=number1;
			}
		}
	}
	for(int i=1;i<=cha;i++)
		s[pera[sumx--].name].a=-1;
}
void findminnb(int cha,int sumx){
	for(int i=1;i<=sumx;i++){
		for(int j=i+1;j<=sumx;j++){
			if(perb[i].number<perb[j].number){
				int name1,number1;
				name1=perb[i].name,number1=perb[i].number;
				perb[i].name=perb[j].name,perb[i].number=perb[j].number;
				perb[j].name=name1,perb[j].number=number1;
			}
		}
	}
	for(int i=1;i<=cha;i++)
		s[perb[sumx--].name].b=-1;
}
void findminnc(int cha,int sumx){
	for(int i=1;i<=sumx;i++){
		for(int j=i+1;j<=sumx;j++){
			if(perc[i].number<perc[j].number){
				int name1,number1;
				name1=perc[i].name,number1=perc[i].number;
				perc[i].name=perc[j].name,perc[i].number=perc[j].number;
				perc[j].name=name1,perc[j].number=number1;
			}
		}
	}
	for(int i=1;i<=cha;i++)
		s[perc[sumx--].name].c=-1;
}
*/
