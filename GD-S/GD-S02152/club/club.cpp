#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct member{
	int m,num;
}a[N][3],b[N];
bool cmp (member x,member y){
	return x.m>y.m;
}
void init(){
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3;j++){
			cin>>b[j].m;
			b[j].num=j;
		}
		sort(b+1,b+4,cmp);
		for (int j=1;j<=3;j++){
			a[i][j].m=b[j].m;
			a[i][j].num=b[j].num;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3;j++){
			cout<<a[i][j].m<<","<<a[i][j].num<<" ";
		}
		cout<<endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		init();
		//solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
