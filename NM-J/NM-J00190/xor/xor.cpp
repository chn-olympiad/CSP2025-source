#include<bits/stdc++.h>
using namespace std;
bool num[1000000][30],tmp2[30],k2[30],t;
long long int n,k,tmp,nim[30];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int x=1;
	for(int a=0;a<30;a++){
		nim[a]=x;
		x*=2;
	}
	for(int b=29;b>=0;b--){
		k2[b]=(k/nim[b])%2;
	}
	for(int a=0;a<n;a++) {
		cin>>tmp;
		for(int b=29;b>=0;b--) {
			if((tmp/nim[b])%2){
				num[a][b]=true;
			}
			else num[a][b]=0;
		}
//		cout<<endl;
//		for(int b=0;b<30;b++) cout<<num[a][b];
//		cout<<endl;
	}
	int ans=0;
	for(int l=0;l<n;l++){
		fill(tmp2,tmp2+30,0);
		for(int r=l;r<n;r++){
			for(int a=0;a<30;a++){
				tmp2[a]=tmp2[a]!=num[r][a];
			}
			t=0;
			for(int a=0;a<30;a++){
				if(tmp2[a]!=k2[a]) {
					t=1;
					break;
				}
			}
			if(!t) ans++;
			
		}
	}
	cout<<ans;
	return 0;
}
