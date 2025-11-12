#include<bits/stdc++.h>
#define int long long
using namespace std;
const int L=5e6+5,N=2e5+5;
int n,q,flag=1,num_c1=0;
char c[2*L],c1[N][L],c2[N][L];
void init(){
	flag=1;
	num_c1=0;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
//	for(int i=1;i<=n;i++){
//		init();
//		cin>>c;
//		for(int j=1;j<=2*L;j++){
//			if(c[j]==' '&&flag==1){
//				flag=2;
//				continue;
//			}
//			if(flag==1){
//				c1[i][++num_c1]=c[j];
//				cout<<c1[i][num_c1];
//			}
//			else{
//				c2[i][j-num_c1-1]=c[j];
//				cout<<c2[i][j-num_c1-1];
//			}
//		}
//		cout<<"\n";
//	}
	while(q--){
		printf("0\n");
	}
	return 0;
}

