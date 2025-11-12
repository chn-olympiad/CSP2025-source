#include<bits/stdc++.h>
using namespace std;
int s[110],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&s[i]);
	int l=s[1];
	sort(s+1,s+n*m+1);
	int i=0,j=1,t=n*m+1;
	while(i<=m-1){
		i++;
		if(j==1){
			t--;
			if(s[t]==l){
				printf("%d %d",i,j);
				return 0;
			}
			while(j<=n-1){
				t--;
				j++;
				if(s[t]==l){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else{
			t--;
			if(s[t]==l){
				printf("%d %d",i,j);
				return 0;
			}
			while(j>=2){
				t--;
				j--;
				if(s[t]==l){
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
	} 
	return 0;
}