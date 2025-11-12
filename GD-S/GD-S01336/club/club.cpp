#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
const int N = 1e5 + 10;
struct node{
	int a,b,c,id;
	int first,second;
}p[N];
int t,n,a1,b1,c1; 
int sum;
struct edge{
	int num,id;
};
bool cmp(edge x,edge y){
	return x.num>y.num;
}
string bi(int x,int y,int z){
	if(x>y&&x>z){
		if(y>z){return "ab";}
		else{return "ac";}
	}
	if(y>z&&y>x){
		if(x>z){return "ba";}
		else{return "bc";}
	}
	if(z>x&&z>y){
		if(x>y){return "ca";}
		else{return "cb";}
	}
}
int main(){
	freopen("club2.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum = a1=b1=c1=0;
		edge a[N],b[N],c[N];
		for(int i = 1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			sum+=max(p[i].a,max(p[i].b,p[i].c))
		}
		if(b1!=-1&&b1>n/2){
			sort(b+1,b+b1+1,cmp);
			while(b1>=n/2){
				sum-=p[b[b1].id].first-p[b[b1].id].second;
				b1--;
			} 
		}
		if(c1!=-1&&c1>n/2){
			sort(c+1,c+c1+1,cmp);
			while(c1>=n/2){
				sum-=p[c[c1].id].first-p[c[c1].id].second;
				c1--;
			} 
		}
		if(a1!=-1&&a1>n/2){
			cout<<"a";
			sort(a+1,a+a1+1,cmp);
			while(a1>=n/2){
				sum-=p[a[a1].id].first-p[a[a1].id].second;
				a1--;
			} 
		}
		cout<<sum<<endl;
	}
	return 0;
}
