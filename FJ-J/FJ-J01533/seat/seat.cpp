#include<bits/stdc++.h>
using namespace std;
bool pd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int chengji[n*m+1];
	int xiaoR;
	for(int i=1;i<=n*m;i++) cin>>chengji[i];
	xiaoR=chengji[1];
	sort(chengji+1,chengji+n*m+1,pd);
	for(int i=1;i<=n*m;i++){
		if(chengji[i]==xiaoR){
			xiaoR=i;
			break;
		}
	}
	int hang,lie;
	if(xiaoR%n==0){
		lie=xiaoR/n;
		if(lie%2) hang=n;
		else hang=1;
	}
	else{
		lie=xiaoR/n+1;
		if(lie%2) hang=xiaoR%n;
		else hang=n-xiaoR%n+1;
	}
	cout<<lie<<" "<<hang;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}