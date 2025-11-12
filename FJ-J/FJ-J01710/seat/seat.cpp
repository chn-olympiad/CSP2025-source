#include<bits/stdc++.h>
using namespace std;
vector<int> s;
int n,m,x,c,r;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>x;
		s.push_back(x);
	}
	x=s[0];
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<n*m;i++){
		if(s[i]==x){
			c=i/n,r=i%n;
			c++,r++;
			break;
		}
	}
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
