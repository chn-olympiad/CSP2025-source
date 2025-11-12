#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	int x=a[0];
	sort(a+0,a+n);
	int c=1,r=1;//cÁÐrÐÐ
	for(int i=n*m;i>0;i--){
		if(a[i]==x){
			cout<<c<<" "<<r;
			break;
		}
		else{
			if(c%2==1){
				if(r+1<=n) r++;
				else if(c+1<=m) c++;
			}
			else{
				if(r-1>=1) r--;
				else if(c+1<=m) c++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
