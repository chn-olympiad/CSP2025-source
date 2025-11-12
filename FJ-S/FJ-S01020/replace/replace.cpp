#include<bits/stdc++.h>
using namespace std;
int n,q,bj,bwz[2];
string eyz[200005][2],wt[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=0;i<n;i++) cin>>eyz[i][0]>>eyz[i][1];
	for (int i=0;i<q;i++){
		int txs=0;
		cin>>wt[i][0]>>wt[i][1];
		int b=0;
		for (int j=0;j<5000005;j++){
			if (wt[i][0][j]=='b'){
				bwz[0]=j;
				b++;
				if (b==2) break;
			}if (wt[i][1][j]=='b'){
				bwz[1]=j;
				b++;
				if (b==2) break;}
		}int bc=bwz[0]-bwz[1]+1;
		for (int j=0;j<n;j++){
			if (eyz[j][0].size()>=bc-1){
				int bb=0,bbb=0,b=0;
				for (int k=0;k<eyz[j][0].size();k++){
					if (eyz[j][0][k]=='b'){
						bb=k;
						b++;
						if (b==2) break;
					}if (eyz[j][1][k]=='b'){
						bbb=k;
						b++;
						if (b==2) break;}
				}if (bb-bbb+1==bc) txs++;
			}
		}cout<<txs<<endl;
	}
}
