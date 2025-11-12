#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,val[5];
	
	cin>>t;
	
	for(int p=1;p<=t;p++){
		int n,maxn=0;
		cin>>n;
		int an[100000][3],md[100000];
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>an[i][j];
			}
		}
		if(n==2){
			maxn=an[0][0]+max(an[1][1],an[1][2]);
			maxn=max(an[0][1]+max(an[1][0],an[1][2]),maxn);
			maxn=max(an[0][2]+max(an[1][0],an[1][1]),maxn);
			val[p]=maxn;
		}
		else{
			for(int i=1;i<=n;i++)
			{
				md[i-1]=an[i-1][0];
			}
			sort(md+1,md+n+1);
			for (int i=0;i<n/2;i++)
			{
				val[p]+=md[n-i];
			}
		}
		
	}
	for(int i=1;i<=t;i++)
	{
		cout<<val[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
