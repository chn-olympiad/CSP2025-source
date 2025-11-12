#include<bits/stdc++.h>
using namespace std;
int m,n,si,i,ha=1,li=1;
bool dirt=1;
vector<int> s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int j=0;j<m*n;j++){
		cin>>si;
		s.push_back(si);
	}
	int ch = s[0];
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	ha++;i++;
	while(s[i]!=ch){
		i++;
		if(ha==1&&dirt==0){li++;dirt=1;continue;}
		if(ha==n&&dirt){li++;dirt=0;continue;}
		if(dirt) ha++;
		else ha--;
	}
	cout<<li<<' '<<ha;
	return 0;
}
