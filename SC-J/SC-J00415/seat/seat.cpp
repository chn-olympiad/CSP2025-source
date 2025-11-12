#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans;
	int a[12][12]={0};
	multiset<int>arr;
	cin>>n>>m;
	cin>>ans;
	arr.insert(ans);
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		arr.insert(x);
	}
	int x=1,y=0;
	bool f=0;
	for(multiset<int>::iterator i=arr.end();i!=arr.begin();){
		i--;
		if(y==n&&f==0){
			x++;
			f=!f;
			y++;
		}
		if(y==1&&f==1){
			x++;
			f=!f;
			y--;	
		}
		if(!f)
			y++;
		else
			y--;
		if(*i==ans){
			cout<<x<<" "<<y;
			return 0;
		}
	}
}