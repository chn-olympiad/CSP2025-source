#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdin);
	int n,m;
	int a[1],b[11000];
	int ans=0,c=0,r=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		c++;
		r++;
		cin>>a[i]>>b[i];
			if(a-b>0){
				c%n;
				r%m;
				cout<<c<<" "<<r;
				break;
			}
			else{
				n-c;
				m-r;
				cout<<c<<" "<<r;
				break;
			}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
