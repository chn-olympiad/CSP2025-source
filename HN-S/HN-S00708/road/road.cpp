#include<bits/stdc++.h>
using namespace std;
int n,m,k,ct[100000];long long s;
struct ti{
	int x,y,z;
}a[100005];
int cmp(ti a,ti b){
	return a.z<b.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		if(ct[a[i].x]==0||ct[a[i].y]==0)s+=a[i].z,ct[a[i].x]++,ct[a[i].y]++;
	}
	cout<<s<<endl;
	return 0;
}

 
