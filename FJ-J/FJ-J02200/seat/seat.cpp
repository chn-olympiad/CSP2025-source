#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	int c=a[1];
	int s=0;
	sort(a+1,a+b+1);
	for(int i=1;i<=b;i++){
		if(a[i]==c){
			if(i<=b/2){
				s=i+1;
				break;
			}
			else{
				s=i-1;
				break;
			}
		}
	}
	int k=0;
	for(int i=1;i<=m;i++){
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				k++;
				if(a[i*j]==c || a[i+j]==c)
				{
					if (s<=n)
					{
						cout<<i<<" "<<j;
						break;
					}
					else if (s>=n)
					{
						cout<<i<<" "<<j;
						break;
					}
				}
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i*j]==c || a[i+j]==c)
				{
					if (s<=n)
					{
						cout<<i<<" "<<j;
						break;
					}
				}
					else if (s>=n)
					{
						cout<<i<<" "<<j;
						break;
					}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
