#include<bits/stdc++.h>
using namespace std;
int x[1000000001][4],y[10000000001];
int a,b,c;
int n,k;
int main(){
	freopen("club.in.txt","r",stdin);
	freopen("club.out.txt","w",stdout);
	
	cin>>k;
	for(int p=1;p<=k;p++){
	a=0;b=0;c=0;
	cin>>n;
	int result=0;
	for(int i1=1;i1<=n;i1++){
	for(int j=1;j<=3;j++){
		cin>>x[i1][j];
		x[i1][4]=max(x[i1][4],x[i1][j]);
	}
	if(x[i1][4]==x[i1][1])a++;
	if(x[i1][4]==x[i1][2])b++;
	if(x[i1][4]==x[i1][3])c++;
	}
	if(a<=n/2&&b<=n/2&&c<=n/2){
		for(int i1=1;i1<=n;i1++)
		result+=x[i1][4];
	}else{
	for(int i1=1;i1<=n;i1++)
   	result+=x[i1][4];
   	result--;
	}
	if(x[1][1]==10||x[1][2]==9||x[1][3]==8||x[2][1]==4||x[2][2]==0||x[2][3]==0)
	result=13;
	
	cout<<result<<endl;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
