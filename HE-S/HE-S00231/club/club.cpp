#include<iostream>
#include<algorithm>
using namespace std;
struct num{
	int x;
	int id;
};
bool f(num a,num b){
	return a.x>b.x;
}
int t,n,sum = 0,xi = 0,yi = 0,zi = 0,p = 0,r = 0,q = 0;
num m[100001];
num o[100001];
num u[100001];
int g[6];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=0;i<=t-1;i++){
		cin>>n;
		for (int j=0;j<=n-1;j++){
			cin>>m[j].x>>o[j].x>>u[j].x;
			m[j].id = o[j].id = u[j].id = i;
}
		sort(m,m+n,f);
		sort(o,o+n,f);
		sort(u,u+n,f);
		for (int k=0;k<=n-1;k++){
			if (m[p].x>=u[r].x && m[p].x>=o[q].x && xi<=n/2){
				sum += m[p].x;
				p++;
				xi++;
				continue;
}
			if (u[r].x>=m[p].x && u[r].x>=o[p].x && yi<=n/2){
				sum += u[r].x;
				r++;
				yi++;
				continue;
}
			if (o[q].x>=m[p].x && o[q].x>=u[r].x && zi<=n/2){
				sum += o[q].x;
				q++;
				zi++;
				continue;
}
}
		g[i] = sum;
		sum = 0;
}
	for (int h=0;h<=t-1;h++){
		cout<<g[h]<<endl;
}
	return 0;
}
