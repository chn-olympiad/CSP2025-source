#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<vector>	
using namespace std;
const int maxn=1e5+10;
int t,n;
struct p{
	int a1,a2,a3;
}a[maxn];

bool cmp1(p x,p y){
	if(x.a1==y.a1){
		if(x.a2==y.a2){
			return x.a3>y.a3;
		}
		return x.a2>y.a2;
	}
	return x.a1>y.a1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		//cout<<'*';
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		//cout<<'$';
		}
		sort(a+1,a+n+1,cmp1);
		int p1,p2,p3;
		p1=p2=p3=n/2;
		int ans=0;
		for(int i=1;i<=n;i++){
			int x=a[i].a1,y=a[i].a2,z=a[i].a3;
			if(x>=y){
				if(x>=z&&p1){
					ans+=x;
					p1--;
				}
				else if(p3){
					ans+=z;
					p3--;
				}
			}
			else{
				if(y>=z&&p2){
					ans+=y;
					p2--;
				}
				else if(p3){
					ans+=z;
					p3--;
				}
			}
		}
		//cout<<'&';
		cout<<ans<<'\n';
		//cout<<'^';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
