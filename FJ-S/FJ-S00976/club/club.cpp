#include<bits/stdc++.h>
using namespace std;
int N,n,z,wa,wb,wc,lsa,lsb,lsc; 
struct ints{
	int a,b,c,d,dj;
}lb[100007],lba[100007],lbb[100007],lbc[100007];
bool cmp(ints a,ints b){return a.dj<b.dj;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	while(N--){
		memset(lb,0,sizeof(lb));
		memset(lba,0,sizeof(lba));
		memset(lbb,0,sizeof(lbb));
		memset(lbc,0,sizeof(lbc));
		z=wa=wb=wc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>lb[i].a>>lb[i].b>>lb[i].c;
		}
		
		for(int i=1;i<=n;i++){
			if (lb[i].a>=lb[i].b && lb[i].a>=lb[i].c) z+=lb[i].a,lba[++wa].a=lb[i].a,lba[wa].b=lb[i].b,lba[wa].c=lb[i].c,lba[wa].d=i;
			else if (lb[i].b>=lb[i].a && lb[i].b>=lb[i].c) z+=lb[i].b,lbb[++wb].a=lb[i].a,lbb[wb].b=lb[i].b,lbb[wb].c=lb[i].c,lbb[wb].d=i;
			else if (lb[i].c>=lb[i].a && lb[i].c>=lb[i].b) z+=lb[i].c,lbc[++wc].a=lb[i].a,lbc[wc].b=lb[i].b,lbc[wc].c=lb[i].c,lbc[wc].d=i;
		}
		
		if (wa>n/2){
			for(int i=1;i<=wa;i++)
				lba[i].dj=lba[i].a-max(lba[i].b,lba[i].c);
			sort(lba+1,lba+1+wa,cmp);
			if (wa>n/2)
				for(int i=1;i<=wa-n/2;i++) z-=lba[i].dj;
		}else if (wb>n/2){
			for(int i=1;i<=wb;i++)
				lbb[i].dj=lbb[i].b-max(lbb[i].a,lbb[i].c);
			sort(lbb+1,lbb+1+wb,cmp);
			if (wb>n/2)
				for(int i=1;i<=wb-n/2;i++) z-=lbb[i].dj;
		}else if (wc>n/2){
			for(int i=1;i<=wc;i++)
				lbc[i].dj=lbc[i].c-max(lbc[i].a,lbc[i].b);
			sort(lbc+1,lbc+1+wc,cmp);
			if (wc>n/2)
				for(int i=1;i<=wc-n/2;i++) z-=lbc[i].dj;
		}
		cout<<z<<endl;
	}
	return 0;
}
/*
3
4 
1 0 0
2 0 0
1 0 0
2 0 0
4 
0 1 0
0 2 0
0 1 0
0 2 0
4 
0 0 1
0 0 2
0 0 1
0 0 2
//
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
1 0 0
1 0 0
2 0 0
2 0 0
2
10 9 8
4 0 0

*/ 
			/*
			lsa=max(max(lb[i].a,lb[i].b),lb[i].c)
			lsc=min(min(lb[i].a,lb[i].b),lb[i].c)
			if (lb[i].a<=lsa && lb[i].a>=lsc) lsb=lb[i].a;
			if (lb[i].b<=lsa && lb[i].b>=lsc) lsb=lb[i].b;
			if (lb[i].c<=lsa && lb[i].c>=lsc) lsb=lb[i].c;
			lb[i].a=lsa,lb[i].b=lsb,lb[i].c=lsc;
			cout<<lsa<<" "<<lsb<<" "<<lsc<<endl;
			*/
			/*
			for(int i=1;i<=wa;i++) cout<<lba[i].dj<<" ";
			cout<<endl;
			cout<<z<<endl;
			*/
