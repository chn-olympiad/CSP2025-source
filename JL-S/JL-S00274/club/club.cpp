#include<bits/stdc++.h>
using namespace std;
struct club{
	int a;
	int b;
	int c;
}l[100002];
int t;
bool cmpa(club a,club b){
	return a.a>b.a;
}
bool cmpb(club a,club b){
	return a.b>b.b;
}
bool cmpb(club a,club b){
	return a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,maxa=0,maxb=0,maxc=0;
		for(int j=1;j<=n;j++){
			cin>>l[j].a>>l[j].b>>l[j].c;
		}
		sort(l+1,l+1+n);
		
	}
	
}
