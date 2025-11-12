#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int main(){
	freopen("xor4.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[N],b[N],c=0;
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	if(k==0 && n<=2){
		if(n==1) cout << 0;
		else cout << 1;
		return 0;
	}
	for(int i = 2;i<=n;i++){
		b[i]=a[i]^b[i-1];
	}
	bool is[n+1]={0};
	int tot=0;
	for(int i = 1;i<=n;i++){
		if(a[i]==k){
			is[i]=1;
			tot++;
//			cout << i << " " << i << endl;
		}
	}
//	cout << endl;
	int p=1;
	for(int i = 1;i<=n;i++){
		if(is[i]){
			i++;
			p=i+1;
			continue;
		}
		
		for(int j = p;j<i;j++){
			if(b[i]^b[j]==k){

				for(int l=j;l<=i;l++) is[l]=1;
				tot++;
//				cout << j << " " << i << endl;
				p=i+1;
				break;
			} 
		}
	}
	cout << tot;
}
