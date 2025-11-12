#include<iostream>
#include<cstdio>
using namespace std;
int n,k[21],a[500010][21],s[500010][21],x,cnt=0,c=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>x;
	while(x>0){
		k[c]=x%2;
		x/=2;
		c++;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		c=1;
		while(x!=0){
			a[i][c]=x%2;
			x/=2;
			c++;
		}
		for(int j=1;j<=20;j++){
			if(s[i-1][j]==a[i][j]){
				s[i][j]=0;
			}else{
				s[i][j]=1;
			}
		}
	}
	int last=1;
	for(int r=1;r<=n;r++){
		for(int l=last;l<=r;l++){
			bool f=true;
			for(int j=1;j<=20;j++){
				int b;
				if(s[l-1][j]==s[r][j]){
					b=0;
				}else{
					b=1;
				}
				if(b!=k[j]){
					f=false;
					break;
				}
			}
			if(f){
				cnt++;
				last=r+1;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}