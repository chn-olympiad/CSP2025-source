#include<bits/stdc++.h>
using namespace std;
int a,b[1000],n,m,ans,c,j,hang,lei;
bool bmp(int x,int y)
 {
 	return x>y;
 }
int main()
{   
  	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ans=n*m;
	for(int i=1;i<=ans;i++)
	 	cin>>b[i]; 
	c=b[1];
	sort(b+1,b+1+ans,bmp);
	for(int i=1;i<=ans;i++)
		if(b[i]==c)   a=i;
    if(a%n==0) lei=a/n;
    else lei=a/n+1;
    if(lei%2==0) 
		hang=n-(a-n*(lei-1))+1;
      else hang=a-n*(lei-1);
    cout<<lei<<" "<<hang;
    fclose(stdin);
	fclose(stdout);
	return 0;
}
