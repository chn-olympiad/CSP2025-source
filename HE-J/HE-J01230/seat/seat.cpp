#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200];
int s,id;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
    	if(a[i]==s){
    		id=i;
    		break;
		}
	}
	 int l=id/n;
	 if(id>l*n) l++;
	 int h;
	if(l%2==1)
	{
		h=(id-1)%n+1;
	}
	else if(l%2==0)
	{    
		h=n-((id-1)%n+1)+1;
	}
     cout<<l<<" "<<h<<'\n';
	return 0;
}
