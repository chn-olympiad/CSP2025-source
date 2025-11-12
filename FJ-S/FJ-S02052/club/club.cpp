#include <bits/stdc++.h>
using namespace std;
int t,n,n1,n2,n3,ss;
struct node{
	long long a1,a2,a3,s;
}x[100005];
bool cmp(node a,node b){
	return a.s>b.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ss=0;
		n1=n2=n3=0;
		for(int i=0;i<n;i++){
			x[i].s=0;
			cin>>x[i].a1>>x[i].a2>>x[i].a3;
			x[i].s+=x[i].a1+x[i].a2+x[i].a3;
		}
		sort(x,x+n,cmp);
		for(int i=0;i<n;i++){
			if(max(max(x[i].a1,x[i].a2),max(x[i].a2,x[i].a3))==x[i].a1&&n1<n/2){
				n1++;
				ss+=x[i].a1;
			}
			else if(max(max(x[i].a1,x[i].a2),max(x[i].a2,x[i].a3))==x[i].a2&&n2<n/2){
				n2++;
				ss+=x[i].a2;
			}
			else{
				n3++;
				ss+=x[i].a3;
			}
		}
		cout<<ss<<endl;
	}
	return 0;
}

