#include<bits/stdc++.h>
using namespace std;
struct CCC{
	int a,b,c;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	CCC m[n+5];
	for(int i=0;i<n;i++){
		cin>>m[i].a>>m[i].b>>m[i].c;
	}
	int q,w,e;
	if(n==2){
		q=m[0].a-m[1].a;
		w=m[0].b-m[1].b;
		e=m[0].c-m[1].c;
	}
	int sum=0;
	cout<<m[0].a+m[1].b;
	return 0;
}
