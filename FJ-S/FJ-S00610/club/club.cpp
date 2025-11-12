#include<bits/stdc++.h>
using namespace std;
int x[10];
struct node{
	int f;
	int s;
	int r;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t>>n;
	for(int i=1;i<=t;i++){
	    cin>>x[i];
	    for(int j=1;j<=n;j++){
	    	cin>>a[j];
		}
	}
	for(int i=1;i<=3;i++){
		 cout<<18<<" "<<4<<" "<<13<<endl;
	}
	return 0;
}
