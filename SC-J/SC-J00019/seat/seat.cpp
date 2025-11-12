#include <bits/stdc++.h>
using namespace std;
int n,m;
int r,s[105],x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	s[0]=r;
	for(int i=1;i<n*m;i++)
		cin>>s[i];
	sort(s,s+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(s[i]==r){
			cout<<y<<" "<<x;
			break;
		}else{
			if((x==n&&y%2)||(x==1&&y%2==0)) y++;
			else{
				if(y%2) x++;
				else x--;
			}
		}	
	}fclose(stdin);
	fclose(stdout);
	return 0;
}