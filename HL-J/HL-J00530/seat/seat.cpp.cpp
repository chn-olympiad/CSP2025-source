#include<bits/stdc++.h>
using namespace std;
struct student{
	int cj;
	int id;
	int id1;
};
student s[105];
int cmp(student s1,student s2){
	if(s1.cj<s2.cj){
		return s1.id<s2.id; 
	}
	return s1.id>s2.id;
}
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b;
	cin>>n>>m;
	int a=n*m;
	for(int i=1;i<=a;i++){
		cin>>s[i].cj;
		s[i].id=i;
		b=s[1].cj;
	}
	sort(s+1,s+a+1,cmp);
	for(int i=1;i<=a;i++){
		if(s[i].cj==b){
			b=i;
		}
	}
	int c=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			c++;
			if(b==c){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}