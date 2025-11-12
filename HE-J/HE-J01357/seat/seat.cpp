#include<bits/stdc++.h>
using namespace std;
int x[1000],y[1000];
bool cmp(int x,int y){
	return x>y;
}
int main()
{	
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	vector<int> a;
	cin>>n>>m;
	int f=0;
	int c=1;
	for(int j=1;j<=m;j++){
	for(int i=1;i<=n;i++){
		
			int t;
			cin>>t;
			a.push_back(t);
			if(j%2==0){
				x[c]=j;
				y[c]=n-i+1;
			}
			else{
			x[c]=j;
			y[c]=i;
				 
			}
			c++;
	}
	}
	f=a[0];
	 sort(a.begin(),a.end(),cmp);
	
	for(int i=0;i<a.size();i++){		
	if(a[i]==f){
		f=i+1;
		break;
	}	
	}	
	cout<<x[f]<<" "<<y[f];
	
	return 0;
	
} 
