#include<bits/stdc++.h>
using namespace std;
int n,m,z[1010];
bool cmp(int a,int b){return a>b;}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>z[i];
    int a=z[1],w=-1;
    sort(z+1,z+1+n*m,cmp);
    for(int i=1;i<=n*m;i++) 
		if(z[i]==a){
    		w=i;
    		break;
		}
//	cout<<w<<'\n';
	int x=1,y=1,fl=1;
	for(int i=1;i<w;i++)
	{
		x+=fl;
//		cout<<x<<' '<<y<<'\n';
		if(x>n) y++,fl=-1,x=n;
		if(x<1) y++,fl=1,x=1;
	}
	cout<<y<<' '<<x;
}
/*
2 2
99 100 97 98
*/
