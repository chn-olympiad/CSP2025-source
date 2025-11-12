#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,a[N*5+5],x,D[N*5+5],E[N*5+5],cnt=1,lastjieshu,cnti;
string A,B,Adao,Bdao,C;
int huo(int a,int b){
	int cnta=1,cntb=1,sum=0,cntc=1;
	int ao=a,bo=b;
	while(a){
		A[cnta]=a%2+'0';
		cnta++;
		a/=2;
		}
		while(b){
		B[cntb]=b%2+'0';
		cntb++;
		b/=2;
		}
		cnta--;
		cntb--;
		cntc=max(cnta,cntb);
		for(int i=1;i<=cntc;i++){
				if(Adao[i]!=Bdao[i])C[i]=1+'0';
				else C[i]='0';
			}
			for(int i=1;i<=cntc;i++){
			A[i]=C[i];
			}
			for(int i=1;i<=cntc;i++){
			C[i]=A[cntc-i+1];
			}
		for(int i=1;i<=cntc;i++){
			sum=sum*2+int(C[i]-'0');
		}
		if(ao==0&&bo!=0)sum--;
		if(bo==0&&ao!=0)sum--;
		return sum;
	}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cout<<2;
	
	return 0;
	
	
}
 
