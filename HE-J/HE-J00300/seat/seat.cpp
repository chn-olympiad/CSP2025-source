#include<bits/stdc++.h>
using namespace std;
int n,m,c=0;
int s[101];
int a[105][105];
/*bool p(int x,int y)
{
	return x>y;
}*/
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>s[i];
		int c=s[1];
		
	}
	cout<<"1"<<" "<<"1";
		
        
    
	//sort(s+1,s+t+1,p);
	
	/*for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
			
			printf("%d",s);
		}
		}
		else{
			for(int j=m;j>=1;j--){
				a[i][j]=s[--c];
				printf("%d",s);
			}
		}
	}*/
    
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
