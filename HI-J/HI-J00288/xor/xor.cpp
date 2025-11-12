#include<bits/stdc++.h>
using namespace std;
int n,k,a[1100][1100],b[1500],c[1100],s;
bool f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int o=j;o<=i;o++){
				a[i][j]=a[i][j]^b[o];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i][j]==k){
				for(int o=j;o<=i;o++){
					if(c[o]==-1){
						f=1;
						break;
					}
				}
				if(f==0){
				s++;
				for(int o=j;o<=i;o++) c[o]=-1;
			}
			else f=0; 
			}
		}
	}
	cout<<s;
	return 0;
} 
