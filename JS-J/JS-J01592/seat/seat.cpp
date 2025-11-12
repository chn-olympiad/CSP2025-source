// need long long ? neednt
// time ? O(nm)
// space ? n*m
// max num ? n=10 m=10
// freopen ? yes
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	vector<int> v;
	cin>>n>>m;
	int r;
	for(int i=0;i<n*m;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	r=v[0];
	sort(v.rbegin(),v.rend());
	int ri;
	for(int i=0;i<(int)v.size();i++)if(v[i]==r){ri=i+1;break;}
	//cout<<ri<<endl;
	int c=ri%(2*n);
	int d=ri/(2*n)+1;
	if(c==0)cout<<2*(d-1)<<' '<<1<<endl;
	else if(c==1)cout<<2*d-1<<' '<<1<<endl;
	else if(c==n)cout<<2*d-1<<' '<<n<<endl;
	else if(c==n+1)cout<<2*d<<' '<<n<<endl;
	else if(c<n)cout<<2*d-1<<' '<<c<<endl;
	else cout<<2*d<<' '<<2*n-c+1<<endl;
	return 0;
}
/*
 * 100 99 98 97 96 95 94 93 92
 * 94:7
 * 7/3+1=3
 * 7%3=1
 * 3 1
 * 
 * 
 * 100 99 98 97
 * 98:3
 * 3/2+1=2
 * 3%2=1
 * 2-1+1=2
 * 2 2
 * 
 * 
 * 100 99 98 97
 * 99:2
 * 2/2=1
 * #Shang4Shan3Ruo6Shui4
*/
