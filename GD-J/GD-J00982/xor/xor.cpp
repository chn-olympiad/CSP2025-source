#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,g;
	cin>>n>>g;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=0;
	for(int k=1;k<=n;k++){
		int z=0;
		for(int i=k;i<=n;i++){
			z=0;
			if(a[i]==-1)continue;
			for(int j=k;j<=i;j++){
				int b=0;
				if(a[j]==-1)continue;
				for(int y=j;y<=i;y++){
					b^=a[y];
				}
				if(b==g){
					for(int y=j;y<=i;y++){
						a[y]=-1;
					}
					t++;
				}
				break;
			}
			
		}
	}
	cout<<t;
	return 0;
}

