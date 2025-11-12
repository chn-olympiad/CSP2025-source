#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct people{
	int a1;
	int a2;
	int a3;
	int gui;
};
int res;
int ag,bg,cg;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		res=0;
		int n;
		cin>>n;
		people peo[n];
		for(int i = 0;i<n;i++){
			cin>>peo[i].a1>>peo[i].a2>>peo[i].a3;
			int lin=max(peo[i].a1,peo[i].a2);
			res+=max(lin,peo[i].a3);
		}
		cout<<res<<endl;
	}
	
	return 0;
}
