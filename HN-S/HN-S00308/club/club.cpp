#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
struct Mer{
	int id;
	int a,b,c;
	int max;
};
vector<Mer> mers;
int c1[N],i1=0;
int c2[N],i2=0;
int c3[N],i3=0;
int t,n,sum=0;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in",r,stdin);
	freopen("club.out",w,stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;cin>>a>>b>>c;
			sum+=max(max(a,b),c);
			c1[i1++]=a;
			c2[i2++]=b;
			c3[i3++]=c;
		}
	}
	cout<<endl;
	sort(c1,c1+n,cmp);
	sort(c2,c2+n,cmp);
	sort(c3,c3+n,cmp);
	for(int i=0;i<3;i++){
		cout<<c1[i]<<" "<<c2[i]<<" "<<c3[i]<<endl;
	}
//	for(int i=0;i<3;i++){
//		sum+=c1[i];
//		sum+=c2[i];
//		sum+=c3[i];
//	}
	cout<<sum;
	return 0;
}
/*
1 
4 
4 2 1
3 2 4
5 3 4
3 5 1
*/ 
