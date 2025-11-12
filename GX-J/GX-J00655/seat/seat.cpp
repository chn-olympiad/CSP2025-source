#include <bits/stdc++.h>
using namespace std;
int main()
{
        freopen("seat.in","r",stdin);
        freopen("seat.out","w",stdout);
        int n,m;
        cin>>n>>m;
        int l=1,h=1,x;
        int c[n*m];
        for(int i=0;i<=n*m-1;i++)
        {
			cin>>c[i];
		}
		int r=c[0];
		sort(c,c+(n*m));	
		for(int i=n*m-1;i>=0;i--)
        {
			if(c[i]==r){
				x=i;
			}
		}	
		for(int i=0;i<=(n*m)-x-2;i++)
        {
			if(l%2==1){
				if(h<n){
					h++;
				}
				else if(h==n){
					l++;
				}
			}
			else if(l%2==0){
				if(h>1){
					h--;
				}
				else if(h==1){
					l++;
					h=1;
				}
			}
		}
		
		if(l%2!=0){
			cout<<h<<" "<<l;
		}
		else if(l%2==0){
			cout<<l<<" "<<h;
		}
		
        return 0;
        //4 4
		//95 100 99 98 97 96 94 93 92 91 90 89 88 87 86 85
}

