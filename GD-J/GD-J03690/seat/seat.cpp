#include<bits/stdc++.h>
using namespace std;
bool cmd(int a,int b){
	return a>b;
}
int n,m,seat[100][100],grade[105],r,lie,hang;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>grade[i];
	}
	r=grade[1];
	sort(grade+1,grade+n*m+1,cmd);
	int paiming=1;
	for(int i=1;i<=n*m;i++){
		if(grade[i]==r) break;
		paiming++;
	}
	if(paiming%m!=0){
		int chufa;
		chufa=paiming/m;
		lie=chufa+1;
		if(chufa%2==0){
			hang=paiming%m;
		}
		else{
			hang=m-(paiming%m)+1;
		}
	}
	else{
		lie=paiming/m;
		if(lie%2==0) hang=m;
		else hang=1;
	}
	cout<<lie<<" "<<hang<<endl;
	return 0;
}
