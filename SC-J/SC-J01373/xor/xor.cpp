#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n=0,tg=0,maxqu=0,tmp=0;
int a[N],qcc=1;
bool flag=false;
struct node{
	int lf,ri;
}qc[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> tg;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==tg){
			maxqu++;
			qc[qcc++].lf=i;
			qc[qcc++].ri=i;
		}
	}
	int r=n;
	for(int j=1;j<=n;j++){
		while(r>j){	
			for(int i=j;i<=r;i++){
				tmp^=a[i];
			}
			for(int i=1;i<=qcc;i++){
				if(r>qc[i].ri && j<qc[i].lf) flag=true;
			}
			if(tmp==tg && !flag) maxqu++;
			qc[qcc++].lf=j;
			qc[qcc++].ri=r;
			r--,flag=false;
		}
		r=n;
	}
	cout << maxqu;
	fclose(stdin);
	fclose(stdout);
	return 0;
}