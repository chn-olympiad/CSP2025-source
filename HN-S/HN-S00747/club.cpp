/*#include<bits/stdc++.h>
using namespace std;
struct node{
	int m1,m2,m3;
};
int n,t;
node a[100050];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
			
		}
		
	}
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int n,t,a[100050],c,b,sum=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>c>>b;
		}
		sort(a+1;a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			sum=0;
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
