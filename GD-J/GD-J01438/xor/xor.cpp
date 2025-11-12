#include<bits/stdc++.h>
namespace zcy{
	using namespace std;
	const int MAXN=5e5+5;
	int a[MAXN];
	int minest[MAXN];
	int w[MAXN]; 
	
	int main(){
		#ifndef debug
		freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
		#endif
		ios::sync_with_stdio(false);
		cin.tie(0);
		
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		
		int mov=0;		//Move Num
		
		for(int i=n;i>=1;i--){
			
//			printf("Come to %d,Now minest:\n",i);
//			for(int j=0;j<8;j++)cout<<(j)<<" "<<minest[j^mov]<<"\n";
//			cout<<endl;
//			printf("Mov:%d\n",mov);
			
			minest[mov]=i;
			
//			printf("Make minest[mov]=%d\nset mov=%d\n",minest[mov],mov^a[i]);
			
			mov^=a[i];
			
			w[i]=w[i+1];
			if(minest[k^mov]){
				//Range from i to minest[k^mov]
//				printf("%d^%d=%d, so make w[%d]=max(%d,%d)\n",k,mov,k^mov,i,w[i+1],w[minest[k^mov]]+1);
				w[i]=max(w[i+1],w[minest[k^mov]+1]+1);
				minest[k^mov]=0;
			}
		}
		
		cout<<w[1]<<endl;
		return 0;
	}
}
int main(){
	zcy::main();
	return 0;
}
