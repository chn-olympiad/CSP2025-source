#include<bits/stdc++.h>
using namespace std;
int k,a[1009],n;
int s[1009][1009];
int b[1009];
int p[1009][1009];
int l[1009][1009];
void lym( int pp, int h){
	
	int cnt=1;
	while(pp>0){
		p[h][cnt]=pp%2;
		pp/=2;
	}b[h]=cnt-1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(k==0){
		cout<<n;
	}else{
		for(int i=1;i<=n;i++){
			lym(a[i],i);
		}for(int i=1;i<=n;i++){
			for(int op=1;op<=b[i];op++){
				l[i][op]=p[i][op];
			}
			for(int j=1;j<=n;j++){
				for(int h=1;h<=max(b[i],b[j]);h++){
					if(l[i][h]==p[j][h]){
						l[i][h]=0;
					}else{
						l[i][h]=1;
					}
				}long long k=1,g=0;
			for(int h=1;h<=18;h++){
				k*=2;
				if(l[i][h]==1){
					g+=k;
				}
			}if(g==k){
				s[i][j]=1;
			}
			}
		}int sum=0;
		for(int i=1;i<=n;i++){
			bool y=1;
			for(int j=1;j<=n;j++){
				if(s[j][i]==1){
					y=0;
				}
			}if(y==0){
				sum++;
			}
		}cout<<sum;
	}
	return 0;
}
