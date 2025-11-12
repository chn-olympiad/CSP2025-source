#include<bits/stdc++.h>
using namespace std;
int m,n;
int c,r;
int t,x;
int s[10000005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>s[i];
	}
	x=s[1];
	for(int i=1;i<=m*n;i++){
		for(int j=1;j<=m*n;j++){
			if(s[j]<s[j+1]){
				t=s[j];
				s[j]=s[j+1];
				s[j+1]=t;
			}
		}
	}
	
	
	for(int i=1;i<=m*n;i++){
		if(x==s[i]){
			for(int j=1;j<=m;j++){
				for(int z=1;z<=n;z++){
					if(s[z]==x && z>=3){
						cout<<z<<' '<<j<<endl;
						break;
					}
					if(s[z]==x){
						cout<<j<<' '<<z<<endl;
						break;
					}
				} 
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
