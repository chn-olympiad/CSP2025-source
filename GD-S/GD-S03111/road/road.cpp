#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
set<int> st;
struct tri{
	int a,b,x;
}f[10111];
bool cmp(tri c,tri d){
	return c.x<d.x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>f[i].a>>f[i].b>>f[i].x;
	sort(f+1,f+m+1,cmp);
	for(int i=1;st.size()!=n;i=i%m+1){
		if((st.find(f[i].a)!=st.end()||st.find(f[i].b)!=st.end())
		&&(st.find(f[i].a)==st.end()||st.find(f[i].b)==st.end())){
			sum+=f[i].x;
			st.insert(f[i].a);
			st.insert(f[i].b);
		}
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
