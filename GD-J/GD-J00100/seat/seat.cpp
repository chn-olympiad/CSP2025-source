#include<bits/stdc++.h>
using namespace std;
int s[110],n,m,a,ch[20][20];
void sor(){
	for(int i=1;i<n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(s[i]<s[j])
			{
				swap(s[i],s[j]);
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&s[i]);
		if(i==1){
			a=s[i]; 
		}
	}
	sor();
	int idx = 1;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				ch[j][i] = s[idx];
				++idx;
			}
		}else{
			for(int j=m;j>=1;j--){
				ch[j][i] = s[idx];
				++idx;
			}
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ch[i][j] == a){
				printf("%d %d",j,i);
				return 0;
			}
		}
	} 
	return 0;
}
