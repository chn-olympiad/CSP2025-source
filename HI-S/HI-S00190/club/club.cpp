#include<bits/stdc++.h>
using namespace std;
int n;
struct ans{
	int x,y,z;

}a[1000001];
int num=0,ans;

int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	int s1=0,s2=0,s3=0;
	while(t!=0){
		cin >> n;
		ans=n/2;
		for(int i=1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;	
		}
		for(int i=1;i<=n;i++){
			int v=max(a[i].x,max(a[i].y,a[i].z));
			num = num+v;
		}
		cout<<num<<endl;
		t--;
	}
	
		
	
	return 0;
}
