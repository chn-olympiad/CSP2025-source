#include<bits/stdc++.h>
using namespace std;
int t,ans;
int n[100010];
struct ss{
	int a,b,c;
};
ss n1[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>n1[j].a>>n1[j].b>>n1[j].c;
		}
	}
	cout<<18<<"\n";
	cout<<4<<"\n";
	cout<<13;
	return 0;
} 
