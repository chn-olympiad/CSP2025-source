#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,s1,s2;
struct node{
	long long a,id;
}q[1000101];
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>q[i].a;
		q[i].id=i;
	}
	sum=q[1].a;
	sort(q+1,q+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
		if(q[i].a==sum){
			s1=i/n;//s1=1
			s2=i%n;//s2=1
			if(s2==0)s2=m;
			if(s2!=0&&s2!=m)s1++;//s1=2
			if(s1%2==1){
				cout<<s1<<" "<<s2;
				return 0;
			}else{
				cout<<s1<<" "<<m-s2+1;
				return 0;
			}
		}
	}
	return 0;
}
/*
2 2
98 99 100 97
100 99 98 97
*/
