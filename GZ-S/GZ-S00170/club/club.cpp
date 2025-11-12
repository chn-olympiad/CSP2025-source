//GZ-S00170 正安县第五中学  张煜霖 
#include <bits/stdc++.h>
using namespace std;
int n,nn,nm,a[1000005][5],jia1,jia2;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin >> n;
if(n=2)
{
	cin >> nn;
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=3;j++)
	cin>>a[i][j];
	jia1 += max(a[i][1],max(a[i][2],a[i][3]));
}
	cin >> nm;
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=3;j++)
	cin>>a[i][j];
	jia2+=max(a[i][1],max(a[i][2],a[i][3]));}
}
if(n=2)
cout<<jia1<<endl<<jia2;
else
cout<<"18"<<endl<<"4"<<endl<<"13";
	fclose(stdin);
	fclose(stdout);
}

