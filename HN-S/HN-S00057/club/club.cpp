#include<bits/stdc++.h>
using namespace std;
int t,n;
struct ren{
	int h[3];
}a[100010];
long long s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].h[0]>>a[i].h[1]>>a[i].h[2];
			s+=max(a[i].h[0],max(a[i].h[1],a[i].h[2]));
		}
		cout<<s<<"\n";
		s=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
