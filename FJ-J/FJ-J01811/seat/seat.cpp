#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout)
	int n,m,num=0;
	cin>>n>>m;
	int c[n*m+1]={};
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int score=c[1];
	sort(c+1,c+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(score==c[i]) num=i;
	}
	int lie=0,hang=0;
	if(num%m!=0){
		lie=num/m+1;
	}else{
		lie=num/m;
	}
	if(lie%2==1){
		hang=num%m;
		if(num%m==0){
			hang+=m;
		}
	}
	if(lie%2==0){
		hang=m+1-num%m;
	}
	cout<<lie<<" "<<hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

