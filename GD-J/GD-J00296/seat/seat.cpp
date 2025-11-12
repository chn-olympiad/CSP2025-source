#include<bits/stdc++.h>
using namespace std;
int n,m,M,ans[3],sco[114];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m*n;i++){
		scanf("%d",&sco[i]);
	}
	M=sco[0];
	sort(sco,sco+n*m,cmp);
	for(int i=0;i<m*n;i++){
		if(M==sco[i]){
			ans[0]=i+1;
			break;
		}
	}
	ans[1]=int(ceil(double(ans[0])/double(n)));
	ans[2]=ans[0]%n;
	if(ans[2]==0){
		ans[2]=n;
	}
	if(ans[1]%2==0){
		ans[2]=n-ans[2]+1;
	}
	printf("%d %d",ans[1],ans[2]);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
