//GZ-S00289 华东师范大学附属贵阳学校 段永琦
#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,a[1000005],b[1000005],c[1000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	sort(c,c+m);
	for(int i=0;i<n-1;i++){
		s+=c[i];
	}
	cout<<s;
	return 0;
}
