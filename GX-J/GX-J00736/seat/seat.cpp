#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	int n,m,t;
	cin>>n>>m;
	vector<int> p;
	for(int i= 0;i < n * m;i++){
		cin>>t;
		p.push_back(t);
	}
	int rs = p[0],temp = 0;
	sort(p.begin(),p.end());
	int f = p.size();
	for(int i = 0;i < f;i++){
		if(p[i] == rs){
			temp = i + 1;
			break;
		}
	}
	temp = f - temp + 1;
	int c,r;
	if(temp % n == 0){
		c = temp / n;
	}
	else{
		c = temp / n + 1;
	}
	if(c % 2 == 1){
		r = temp % m;
	}
	else if(c % 2 == 0){
		r = n - (temp % m) + 1;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
