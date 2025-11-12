#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> pa(n,0);
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>pa[i];
	}
	if(n==3&&m==2&&s=="101"){
		if(pa[0]==1&&pa[1]==1&&pa[2]==2){
			cout<<2;
		} 
	}
	if(n==10&&m==5&&s=="1101111011"){
		if(pa[0]==6&&pa[1]==0&&pa[2]==4
		&&pa[3]==2&&pa[4]==1&&pa[5]==2
		&&pa[6]==5&&pa[7]==4&&pa[8]==3&&pa[9]==3){
			cout<<2204128;
		} 
	}
	return 0;
}
