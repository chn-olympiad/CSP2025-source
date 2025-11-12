#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s=0,pai=1;
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=n*m;i++){
		int j;
		cin>>j;
		if(j>s) pai++;
	}
	int lie=0,hang=0;
	if(pai%n!=0){
		lie=pai/n+1;
	}else{
		lie=pai/n;
	}
	int j=pai-(lie-1)*n;
	if(lie%2==0){
		hang=n-j+1;
	}else hang=j;
	cout<<lie<<" "<<hang;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

