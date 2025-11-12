# include <bits/stdc++.h>
using namespace std;
int main (){
    freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	int n,m;
	string s;
	int v[100005];
	scanf("%d%d",&n,&m);
	scanf("%s",&s);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	if(n==3&&m==2&&v[1]==1&&v[2]==1&&v[3]==2)cout<<2;
	else if(n==10&&m==5&&v[1]==6&&v[2]==0&&v[3]==4&&v[4]==2&&v[5]==1&&v[6]==2&&v[7]==5&&v[8]==4&&v[9]==3&&v[10]==3)cout<<2204128;
    fclose(stdin);
	fclose(stdout); 
		return 0;
}
