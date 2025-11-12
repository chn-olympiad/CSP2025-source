#include<bits/stdc++.h>
using namespace std;
long long aaa[1000010]; 
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>aaa[i];
	}
	long long s=aaa[0];
	sort(aaa,aaa+n*m,cmp);
	int x=1,y=1;
	for(int i=0;i<n*m;i++){
		if(aaa[i]==s) cout<<x<<" "<<y;
		else{
			if(y==n&&x%2==1) x++;
			else if(y==1&&x%2==0) x++;
			else if(x%2==0) y--;
			else if(x%2==1) y++;
		}
	}
	return 0;
}

