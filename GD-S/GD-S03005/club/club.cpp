#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t;

struct manb{
	int a;
	int b;
	int c;
};
manb cluba[N],clubb[N],clubc[N];
manb manbe;
bool cmpa(manb a,manb b){
	if(max((a.a-a.b),(a.a-a.c))>=max((b.a-b.b),(b.a-b.c))){
		return a.a<b.a;
	}
	else{
		return b.a<a.a;
	}
}
bool cmpb(manb a,manb b){
	if(max((a.c-a.b),(a.a-a.b))>=max((b.a-b.b),(b.c-b.b))){
		return a.b<b.b;
	}
	else{
		return b.b<a.b;
	}
}
bool cmpc(manb a,manb b){
	if(max((a.b-a.c),(a.a-a.c))>=max((b.b-b.c),(b.a-b.c))){
		return a.c<b.c;
	}
	else{
		return b.c<a.c;
	}
}

int sum = 0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	
	for(int i = 1; i <= t;i ++){
		int n;
		cin >> n;
		int A[N]; 
		bool fg1 = 1;
		
		int cnta=1,cntb=1,cntc=1;
		for(int j = 1; j <= n;j++){
			int t1,t2,t3;
			cin >>t1 >>t2>>t3;
			manbe.a = t1;
			manbe.b = t2;
			manbe.c = t3;
			A[j] = t1;
			if(manbe.b!=0||manbe.c!=0){
				fg1 = 0;
			}
			if(manbe.a>=manbe.b&&manbe.a>=manbe.c){
				cluba[cnta] = manbe;
				cnta++;
			}
			else if(manbe.c>=manbe.b&&manbe.c>=manbe.a){
				clubb[cntb] = manbe;
				cntb++;
			}
			else{
				clubc[cntc] = manbe;
				cntc++;
			}
			while((cnta-1)>(n/2)){
				sort(cluba+1,cluba+1+cnta,cmpa);
				manb tmp = cluba[cnta];
				cnta--;
				if(cntb<=(n/2)&&cntc<=(n/2)){
					if((tmp.c-tmp.a)>(tmp.b-tmp.a)){
						clubc[cntc]=tmp;
						cntc++;
					}
					else{
						clubb[cntb]=tmp;
						cntb++;
					}
				}
				else if(cntb<=(n/2)){
					clubb[cntb]=tmp;
					cntb++;
				}
				else{
					clubc[cntc]=tmp;
					cntc++;
				}
			}
			while((cntb-1)>(n/2)){
				sort(clubb+1,clubb+1+cntb,cmpb);
				manb tmp = clubb[cntb];
				cntb--;
				if(cnta<=(n/2)&&cntc<=(n/2)){
					if((tmp.c-tmp.b)>(tmp.a-tmp.b)){
						clubc[cntc]=tmp;
						cntc++;
					}
					else{
						cluba[cnta]=tmp;
						cnta++;
					}
				}
				else if(cnta<=(n/2)){
					cluba[cnta]=tmp;
					cnta++;
				}
				else{
					clubc[cntc]=tmp;
					cntc++;
				}
			}
			while((cntc-1)>(n/2)){
				sort(clubc+1,clubc+1+cntc,cmpc);
				manb tmp = clubc[cntc];
				cntc--;
				if(cntb<=(n/2)&&cnta<=(n/2)){
					if((tmp.b-tmp.c)>(tmp.a-tmp.c)){
						clubb[cntb]=tmp;
						cntb++;
					}
					else{
						clubc[cntc]=tmp;
						cntc++;
					}
				}
				else if(cntb<=(n/2)){
					clubb[cntb]=tmp;
					cntb++;
				}
				else{
					cluba[cnta]=tmp;
					cnta++;
				}
			}
		}
			if(fg1){
				sort(A+1,A+n+1);
				int sum2 = 0;
				for(int i = n; i> ceil(n*1.0/2);i--){
					sum2 += A[i];
				}
				cout << sum2<<endl;
				continue;
			}
			for(int i = 1; i < cnta; i ++){
				sum += cluba[i].a;
			}
			for(int i = 1; i < cntb; i ++){
				sum += clubb[i].b;
			}
			for(int i = 1; i < cntc; i ++){
				sum += clubc[i].c;
			}
			cout << sum<<endl;
		}
	
	return 0;
}

		
			
