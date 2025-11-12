#include <bits/stdc++.h>
using namespace std;
struct state {
	int m[4];
	int visited;
	int id;
}a[30000];
int t, n, c[4]={0,0,0,0}, ans=0;
void display(void){
cout<<endl;	for(int i=1;i<=n;i++)cout<<a[i].id<<":"<<a[i].m[1]<<" "<<a[i].m[2]<<" "<<a[i].m[3]<<" "<<a[i].visited<<endl;
}
bool comp1(state n1,state n2){
	if(n1.m[1]>=n2.m[1]) return 1;
	else return 0;
}
bool comp2(state n1,state n2){
	if(n1.m[2]>=n2.m[2]) return 1;
	else return 0;
}
bool comp3(state n1,state n2){
	if(n1.m[3]>=n2.m[3]) return 1;
	else return 0;
}
void makeit() {
	sort(a+1,a+n+1,comp1);
	for(int i=1;i<=(int)n/2;i++){
		//ans+=a[i].m[1];
		a[i].visited=1;
	}
	sort(a+1,a+n+1,comp2);
	for(int i=1;i<=n;i++){
		if(a[i].visited==0) {
			//ans+=a[i].m[2];
			a[i].visited=2;
			c[2]++;
		}
		else if(a[i].visited!=2&&a[i].m[2]>a[i].m[1]){
			//ans=ans-a[i].m[1]+a[i].m[2];
			a[i].visited=2;
		}
		if(c[2]>=(int)n/2)break;
	}
	sort(a+1,a+n+1,comp3);
	for(int i=1;i<=n;i++){
		if(a[i].visited==0) {
			//ans+=a[i].m[3];
			a[i].visited=3;
			c[3]++;
		}
		else if(a[i].visited!=3&&a[i].m[3]>a[i].m[a[i].visited]){
			//ans=ans-a[i].m[a[i].visited]+a[i].m[3];
			a[i].visited=3;
		}
		if(c[3]>(int)n/2)break;
	}
	for(int i =1;i<=n;i++)ans+=a[i].m[a[i].visited];
	cout<<ans<<endl;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t --) {
		cin>>n;
		for(int i = 1; i <= n; i ++) {
			cin>>a[i].m[1]>>a[i].m[2]>>a[i].m[3];
			a[i].visited=0;
			a[i].id=i;
		}
		
		makeit();
		ans = 0;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
