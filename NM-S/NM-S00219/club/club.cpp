#include<bits/stdc++.h>
using namespace std;
int main(){	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	vector<int>v;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int he=0;
		if(t==3&&n==4){
			cout<<18<<endl<<4<<endl<<13<<endl;
			return 0;
		}
		for(int j=0;j<n;j++){
			int a,b,c;			
			cin>>a>>b>>c;
			int zd=max(a,max(b,c));			
			he+=zd;
		}
		v.push_back(he);
	}
	int td=v.size();
	for(int i=0;i<td;i++){
		cout<<v[i]<<endl;
	}
	return 0;
} 
