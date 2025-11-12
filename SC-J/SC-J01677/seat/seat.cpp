#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	vector <int> l;
	int n,m,x,p,a=1,c=1,r=1;
	cin>>n>>m;
	
	cin>>p;
	l.push_back(p);
	
	for(int i=1;i<=n*m-1;i++){
		cin>>x;
		l.push_back(x);
	}
	sort(l.begin(),l.end(),cmp);
	for(int i=0;i<l.size();i++){
		if(a==1){
			if(l[i]!=p&&c<n) c++;
			else if(l[i]!=p&&c==n){
				a=2;
				r++;
			}
			if(l[i]==p) break;
		}
		else if(a==2){
			if(l[i]!=p&&c>1) c--;
			else if(l[i]!=p&&c==1){
				a=1;
				r++;
			}
			if(l[i]==p) break;
		}
	}
	cout<<r<<' '<<c;
	return 0;
} 